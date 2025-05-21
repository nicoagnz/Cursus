/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:39:52 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/20 12:04:55 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pipex(char **av, char **env)
{
	int		status;
	int		pipefd[2];
	pid_t	pid;

	status = 0;
	if (pipe(pipefd) == -1)
		ft_msg_error("pipe");
	pid = fork();
	if (pid == -1)
		ft_msg_error("fork");
	if (pid == 0)
		ft_first_child(av, env, pipefd);
	else
	{
		waitpid(pid, NULL, 0);
		status = ft_parent(av, env, pipefd);
	}
	return (status);
}

int	main(int ac, char **av, char **env)
{
	int	status;

	if (ac != 5)
		exit(EXIT_FAILURE);
	status = ft_pipex(av, env);
	return (status);
}
