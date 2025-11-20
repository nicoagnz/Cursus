/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 12:30:20 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/19 11:36:42 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	**process_unset_var(char **env, char *var)
{
	char	**new_env;
	char	**temp;

	new_env = create_new_env(env, var);
	if (!new_env)
		return (env);
	if (new_env != env)
	{
		temp = env;
		env = new_env;
		ft_free_env(temp);
	}
	else
		ft_free_env(new_env);
	return (env);
}

char	**ft_builtin_unset(char **args, char **env)
{
	int	i;

	if (!args || !env || !args[1])
		return (env);
	i = 1;
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			printf("unset: `%s': not a valid identifier\n", args[i]);
			i++;
			continue ;
		}
		env = process_unset_var(env, args[i]);
		i++;
	}
	return (env);
}
