/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:17:12 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/21 09:31:22 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_first_child(char **av, char **env, int *pipefd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0644);
	if (infile < 0)
		ft_msg_error("open");
	close(pipefd[0]);
	if (dup2(infile, STDIN_FILENO) < 0)
		ft_msg_error("dup2");
	close(infile);
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		ft_msg_error("dup2");
	close(pipefd[1]);
	if (ft_av_valid(av[2]) == 0)
		ft_msg_error("path");
	ft_exec_cmd(av[2], env);
}

void	ft_second_child(char **av, char **env, int *pipefd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		ft_msg_error("open");
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		ft_msg_error("dup2");
	close(pipefd[0]);
	if (dup2(outfile, STDOUT_FILENO) < 0)
		ft_msg_error("dup2");
	close(outfile);
	if (ft_av_valid(av[3]) == 0)
		ft_msg_error("path");
	ft_exec_cmd(av[3], env);
}

int	ft_parent(char **av, char **env, int *pipefd)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	close (pipefd[1]);
	if (pid == -1)
		ft_msg_error("fork");
	if (pid == 0)
		ft_second_child(av, env, pipefd);
	else
	{
		waitpid(pid, &status, 0);
		close(pipefd[0]);
	}
	return (WEXITSTATUS(status));
}

int	ft_av_valid(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (-1);
	while (av[i] && av[i] == ' ')
		i++;
	if (av[i] && av[i] != ' ')
		return (1);
	return (0);
}
