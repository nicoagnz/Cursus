/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:42:31 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/19 11:36:35 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_builtin_env(char **env)
{
	int	i;

	i = 0;
	if (env == NULL)
	{
		perror("env");
		return (1);
	}
	while (env[i] && env)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}

static void	free_env_array(char **env, int up_to)
{
	while (--up_to >= 0)
		free(env[up_to]);
	free(env);
}

static int	count_env(char **env)
{
	int	count;

	count = 0;
	while (env[count])
		count++;
	return (count);
}

char	**dup_env(char **env)
{
	char	**new_env;
	int		count;
	int		i;

	if (!env)
		return (NULL);
	count = count_env(env);
	new_env = (char **)malloc((count + 1) * sizeof(char *));
	if (!new_env)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
		{
			free_env_array(new_env, i);
			return (NULL);
		}
	}
	new_env[count] = NULL;
	return (new_env);
}
