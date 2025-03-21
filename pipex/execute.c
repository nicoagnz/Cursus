/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:50:23 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/21 11:22:00 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_path(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		paths[i++] = NULL;
	}
	free(paths);
	paths = NULL;
}

int	find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	return (i);
}

char	*ft_get_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*temp;

	i = find_path(env);
	if (!env[i])
		return (NULL);
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_path, F_OK) == 0)
		{
			ft_free_path(paths);
			return (full_path);
		}
		free(full_path);
	}
	ft_free_path(paths);
	return (NULL);
}

void	ft_exec_cmd(char *av, char **env)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(av, ' ');
	path = ft_get_path(cmd[0], env);
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		ft_msg_error("path");
	}
	if (execve(path, cmd, env) == -1)
	{
		free(path);
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		ft_msg_error("execve\n");
	}
}

void	ft_msg_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	if (ft_strncmp(msg, "execve", 6) == 0 || ft_strncmp(msg, "path", 4) == 0)
		exit(127);
	exit(EXIT_FAILURE);
}
