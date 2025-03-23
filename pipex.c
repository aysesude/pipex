/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:30:19 by aycami            #+#    #+#             */
/*   Updated: 2025/03/23 01:26:52 by aycami           ###   ########.fr       */
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

void	child_process(t_var *var, char **argv, char **envp)
{
	if (var->infile < 0 || var->outfile < 0)
		ft_error("File error");
	if (pipe(var->fd) == -1)
		ft_error("pipe error");
	var->pid1 = fork();
	if (var->pid1 < 0)
		ft_error("fork failed");
	first_child(var, argv, envp);
	var->pid2 = fork();
	if (var->pid2 < 0)
		ft_error("fork failed");
	second_child(var, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_var	var;

	if (argc != 5)
	{
		write(1, "Error: Wrong number of arguments\n", 33);
		exit(1);
	}
	var.infile = open(argv[1], O_RDONLY);
	var.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	child_process(&var, argv, envp);
	close(var.fd[0]);
	close(var.fd[1]);
	close(var.infile);
	close(var.outfile);
	waitpid(var.pid1, NULL, 0);
	waitpid(var.pid2, NULL, 0);
	return (0);
}
