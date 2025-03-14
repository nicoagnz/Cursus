/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:39:52 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/13 11:21:08 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*open_files(char *infile, char *outfile)
{
	int	*files;

	files = malloc(sizeof(int) * 2);
	if (!files)
		error_exit(0, "malloc failed", NULL, NULL);
	files[0] = open(infile, O_RDONLY);
	if (files[0] == -1)
	{
		free(files);
		ft_printf("pipex: no such file or directory: %s\n", infile);
		exit(1);
	}
	files[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (files[1] == -1)
	{
		close(files[0]);
		free(files);
		ft_printf("pipex: permission denied: %s\n", outfile);
		exit(1);
	}
	return (files);
}

char	**div_command(char *cmd)
{
	char	**args;
	int		j;

	j = 0;
	args = ft_split(cmd, ' ');
	if (!args)
	{
		while (args[j])
			free(args[j++]);
		free(args);
		error_exit(0, "split failed", NULL, NULL);
	}
	return (args);
}

char	*get_full_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*full_path;

	i = 0;
	paths = get_path_env(env);
	if (!paths)
		error_exit(1, "PATH not found in environment", paths, NULL);
	while (paths[++i])
	{
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			error_exit(0, "malloc failed", NULL, full_path);
		ft_strlcpy(full_path, paths[i], ft_strlen(paths[i]) + 1);
		ft_strlcat(full_path, "/", ft_strlen(paths[i]) + 2);
		ft_strlcat(full_path, cmd, ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (access(full_path, F_OK) == 0)
		{
			free(paths);
			return (full_path);
		}
		free(full_path);
	}
	free(paths);
	return (NULL);
}

char	**get_path_env(char **env)
{
	int		i;
	int		j;
	char	**path;

	i = 0;
	j = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (!env[i])
		return (NULL);
	path = ft_split(env[i] + 5, ':');
	if (!path)
	{
		while (path[j])
			free(path[j++]);
		free(path);
		error_exit(0, "split failed", NULL, NULL);
	}
	return (path);
}

void	error_exit(int i, const char *msg, char **args_paths, char *cmd_path)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		free(cmd_path);
		ft_printf("%s", msg);
		exit(1);
	}
	else if (i == 1)
	{
		while (args_paths[j])
			free(args_paths[j++]);
		free(args_paths);
		ft_printf("pipex: command not found: %s\n", msg);
		exit(127);
	}
	else if (i == 2)
	{
		free(args_paths);
		free(cmd_path);
		ft_printf("pipex: execution failed: %s\n", msg);
		exit(126);
	}
}
