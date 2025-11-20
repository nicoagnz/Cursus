/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:00:00 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/19 11:36:44 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_remove_last_dir(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	while (i > 0 && path[i] == '/')
		i--;
	while (i > 0 && path[i] != '/')
		i--;
	if (i == 0)
		path[1] = '\0';
	else
		path[i] = '\0';
}

void	ft_strjoin_path(const char *base, const char *rel, char *result)
{
	ft_strlcpy(result, base, MAX_PROMPT_SIZE);
	if (result[ft_strlen(result) - 1] != '/')
		ft_strlcat(result, "/", MAX_PROMPT_SIZE);
	ft_strlcat(result, rel, MAX_PROMPT_SIZE);
}

int	find_valid_parent(char *oldpwd, char *newpwd)
{
	size_t	prev_len;

	ft_strlcpy(newpwd, oldpwd, MAX_PROMPT_SIZE);
	while (ft_strlen(newpwd) > 1)
	{
		prev_len = ft_strlen(newpwd);
		ft_remove_last_dir(newpwd);
		if (ft_strlen(newpwd) == prev_len)
			break ;
		if (chdir(newpwd) == 0)
			return (1);
	}
	ft_strlcpy(newpwd, "/", MAX_PROMPT_SIZE);
	if (chdir("/") == 0)
		return (1);
	return (0);
}

void	get_oldpwd(char oldpwd[MAX_PROMPT_SIZE], t_data *data)
{
	char	*pwd_env;
	int		i;

	pwd_env = NULL;
	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PWD=", 4) == 0)
		{
			pwd_env = data->env[i] + 4;
			break ;
		}
		i++;
	}
	if (pwd_env)
		ft_strlcpy(oldpwd, pwd_env, MAX_PROMPT_SIZE);
	else
		oldpwd[0] = '\0';
}

char	*get_oldpwd_path(t_data *data)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (data->env[i] && !path)
	{
		if (ft_strncmp(data->env[i], "OLDPWD=", 7) == 0)
			path = data->env[i] + 7;
		i++;
	}
	return (path);
}
