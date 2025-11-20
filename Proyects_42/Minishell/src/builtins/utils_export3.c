/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctaboada <ctaboada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:00:00 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/17 12:00:00 by ctaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_valid_identifier(char *arg)
{
	int	i;

	if (!arg || !arg[0] || (!ft_isalpha(arg[0]) && arg[0] != '_'))
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	print_export_var(char *var)
{
	char	*equal;
	char	*key;

	equal = ft_strchr(var, '=');
	if (equal)
	{
		key = ft_substr(var, 0, equal - var);
		if (key)
		{
			printf("declare -x %s=\"%s\"\n", key, equal + 1);
			free(key);
		}
	}
	else
		printf("declare -x %s\n", var);
}

char	**handle_no_args(char **env)
{
	char	**env_copy;

	env_copy = dup_env(env);
	if (!env_copy)
	{
		ft_putendl_fd("minishell: export: failed to duplicate environment",
			STDERR_FILENO);
		return (env);
	}
	ft_export_print(env_copy);
	ft_free_env(env_copy);
	return (env);
}

void	print_invalid_id_error(char *arg)
{
	ft_putstr_fd("minishell: export: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
}

char	**process_export_args(char **arg, char **env)
{
	int		i;
	char	**new_env;
	char	**temp_env;

	i = 1;
	new_env = env;
	while (arg[i])
	{
		if (!is_valid_identifier(arg[i]))
			print_invalid_id_error(arg[i]);
		else
		{
			temp_env = add_or_update_env(new_env, arg[i]);
			if (!temp_env)
				ft_putendl_fd("minishell: export: error to add/update variable",
					STDERR_FILENO);
			else
				new_env = temp_env;
		}
		i++;
	}
	return (new_env);
}
