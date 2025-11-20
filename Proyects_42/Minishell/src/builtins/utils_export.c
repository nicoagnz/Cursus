/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:56:07 by ctaboada          #+#    #+#             */
/*   Updated: 2025/10/02 12:41:49 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_is_sorted(char **env, int count)
{
	int	i;

	i = 0;
	if (!env)
		return (1);
	while (i < count - 1)
	{
		if (env[i] && env[i + 1] && ft_strcmp(env[i], env[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_env(char **env, int count)
{
	int		i;
	char	*tmp;

	if (!env)
		return ;
	while (!ft_is_sorted(env, count))
	{
		i = 0;
		while (i < count - 1)
		{
			if (env[i] && env[i + 1] && ft_strcmp(env[i], env[i + 1]) > 0)
			{
				tmp = env[i];
				env[i] = env[i + 1];
				env[i + 1] = tmp;
			}
			i++;
		}
	}
}

void	free_old_env(char **env)
{
	int	j;

	j = 0;
	while (env && env[j])
	{
		free(env[j]);
		j++;
	}
	free(env);
}

char	*extract_key(char *var)
{
	char	*equal_sign;
	char	*key;

	equal_sign = ft_strchr(var, '=');
	if (!equal_sign)
		return (NULL);
	key = ft_substr(var, 0, equal_sign - var);
	return (key);
}

char	**add_or_update_env(char **env, char *var)
{
	int		i;
	char	*key;
	char	**new_env;

	if (!var)
		return (env);
	key = extract_key(var);
	if (!key)
		return (env);
	i = 0;
	while (env && env[i])
	{
		if (is_matching_key(env[i], key))
			return (update_existing_var(env, var, key, i));
		i++;
	}
	new_env = add_new_env(env, var);
	free(key);
	if (!new_env)
		return (env);
	if (new_env != env)
		free_old_env(env);
	return (new_env);
}
