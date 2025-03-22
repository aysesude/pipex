/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:30:19 by aycami            #+#    #+#             */
/*   Updated: 2025/03/22 14:46:56 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*args[4];

	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = cmd;
	args[3] = NULL;
	if (execve("/bin/sh", args, envp) == -1)
		ft_error("execve failed");
}

void	first_child(t_var var, char **argv, char **envp)
{
	if (var.pid1 == 0)
	{
		dup2(var.infile, STDIN_FILENO);
		dup2(var.fd[1], STDOUT_FILENO);
		close(var.fd[0]);
		close(var.fd[1]);
		close(var.infile);
		execute_cmd(argv[2], envp);
	}
}

void	second_child(t_var var, char **argv, char **envp)
{
	if (var.pid2 == 0)
	{
		dup2(var.fd[0], STDIN_FILENO);
		dup2(var.outfile, STDOUT_FILENO);
		close(var.fd[0]);
		close(var.fd[1]);
		close(var.outfile);
		execute_cmd(argv[3], envp);
	}
}

void	child_process(t_var var, char **argv, char **envp)
{
	if (var.infile < 0 || var.outfile < 0)
		ft_error("File error");
	if (pipe(var.fd) == -1)
		ft_error("pipe error");
	var.pid1 = fork();
	if (var.pid1 < 0)
		ft_error("fork failed");
	first_child(var, argv, envp);
	var.pid2 = fork();
	if (var.pid2 < 0)
		ft_error("fork failed");
	second_child(var, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_var	var;

	if (argc != 5)
		ft_error ("Error: Wrong number of arguments\n");
	var.infile = open(argv[1], O_RDONLY);
	var.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	child_process(var, argv, envp);
	close(var.fd[0]);
	close(var.fd[1]);
	close(var.infile);
	close(var.outfile);
	waitpid(var.pid1, NULL, 0);
	waitpid(var.pid2, NULL, 0);
	return (0);
}
