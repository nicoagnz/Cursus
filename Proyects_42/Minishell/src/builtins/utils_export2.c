/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:00:00 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/17 12:00:00 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	free_partial_env(char **env, int count)
{
	while (--count >= 0)
		free(env[count]);
	free(env);
}

static char	**copy_env_vars(char **env, char **new_env, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		new_env[i] = ft_strdup(env[i]);
		if (!new_env[i])
		{
			free_partial_env(new_env, i);
			return (NULL);
		}
		i++;
	}
	return (new_env);
}

char	**add_new_env(char **env, char *new_var)
{
	int		count;
	char	**new_env;

	count = 0;
	while (env && env[count])
		count++;
	new_env = malloc((count + 2) * sizeof(char *));
	if (!new_env)
		return (NULL);
	if (!copy_env_vars(env, new_env, count))
		return (NULL);
	new_env[count] = ft_strdup(new_var);
	if (!new_env[count])
	{
		free_partial_env(new_env, count);
		return (NULL);
	}
	new_env[count + 1] = NULL;
	return (new_env);
}

int	is_matching_key(char *env_var, char *key)
{
	size_t	key_len;

	key_len = ft_strlen(key);
	if (ft_strncmp(env_var, key, key_len) == 0)
	{
		if (env_var[key_len] == '=' || env_var[key_len] == '\0')
			return (1);
	}
	return (0);
}

char	**update_existing_var(char **env, char *var, char *key, int i)
{
	char	*temp;

	temp = ft_strdup(var);
	if (!temp)
	{
		free(key);
		return (env);
	}
	free(env[i]);
	env[i] = temp;
	free(key);
	return (env);
}
