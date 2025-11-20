/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:01:25 by ctaboada          #+#    #+#             */
/*   Updated: 2025/11/19 11:36:38 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_env(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

void	ft_export_print(char **env)
{
	int		i;
	char	**sorted;

	if (!env)
		return ;
	sorted = dup_env(env);
	if (!sorted)
	{
		ft_putendl_fd("minishell: export: memory allocation failed",
			STDERR_FILENO);
		return ;
	}
	i = 0;
	while (sorted[i])
		i++;
	ft_sort_env(sorted, i);
	i = 0;
	while (sorted[i])
	{
		print_export_var(sorted[i]);
		i++;
	}
	ft_free_env(sorted);
}

char	**ft_builtin_export(char **arg, char **env)
{
	if (!arg || !env)
		return (env);
	if (!arg[1])
		return (handle_no_args(env));
	return (process_export_args(arg, env));
}
