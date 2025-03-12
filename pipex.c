/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aycami <aycami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 18:30:19 by aycami            #+#    #+#             */
/*   Updated: 2025/02/23 15:46:50 by aycami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *cmd, char **envp)
{
	char	*args[] = {"/bin/sh", "-c", cmd, NULL};
	if (execve("/bin/sh", args, envp) == -1)
	{
		perror("execve failed");
		exit(127);
	}
}

void first_child(pid_t pid1, int infile, int *fd, char **argv, char **envp)
{
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(infile); 
		execute_cmd(argv[2], envp);
	}
}

void second_child(pid_t pid2, int outfile, int *fd, char **argv, char **envp)
{
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(outfile); 
		execute_cmd(argv[3], envp);
	}
}

int main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1, pid2;
	int		infile, outfile;

	if (argc != 5)
	{
		ft_printf("Error: Wrong number of arguments\n");
		exit(1);
	}

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile < 0 || outfile < 0)
	{
		perror("File error");
		exit(1);
	}

	if (pipe(fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork failed");
		exit(1);
	}
	first_child(pid1, infile, fd, argv, envp);

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork failed");
		exit(1);
	}
	second_child(pid2, outfile, fd, argv, envp);

	close(fd[0]);
	close(fd[1]);
	close(infile);
	close(outfile);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
