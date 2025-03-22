/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aysesudecami <aysesudecami@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:47:33 by aysesudecam       #+#    #+#             */
/*   Updated: 2025/03/22 14:47:52 by aysesudecam      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
