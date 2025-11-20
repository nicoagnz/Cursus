/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:00:00 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/19 11:36:50 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_env_vars(char **env)
{
	int	size;

	if (!env)
		return (0);
	size = 0;
	while (env[size])
		size++;
	return (size);
}

int	get_var_name_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
}

int	should_keep_var(char *env_var, char *var_to_remove, int var_len)
{
	int	env_var_len;

	env_var_len = get_var_name_length(env_var);
	if (ft_strncmp(env_var, var_to_remove, var_len) != 0
		|| var_len != env_var_len)
		return (1);
	return (0);
}

static char	**copy_filtered_env(char **env, char **new_env,
						char *var_to_remove, int var_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (should_keep_var(env[i], var_to_remove, var_len))
		{
			new_env[j] = ft_strdup(env[i]);
			if (!new_env[j])
			{
				ft_free_env(new_env);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}

char	**create_new_env(char **env, char *var_to_remove)
{
	int		var_len;
	char	**new_env;

	var_len = ft_strlen(var_to_remove);
	new_env = malloc(sizeof(char *) * (count_env_vars(env) + 1));
	if (!new_env)
		return (NULL);
	return (copy_filtered_env(env, new_env, var_to_remove, var_len));
}
