/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:42:58 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:37:09 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	fatal_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}

static char	*create_shlvl_var(int shlvl)
{
	char	*shlvl_str;
	char	*new_var;

	if (shlvl < 0)
		shlvl = 0;
	shlvl++;
	shlvl_str = ft_itoa(shlvl);
	if (!shlvl_str)
		fatal_error("Error allocating memory for SHLVL");
	new_var = ft_strjoin("SHLVL=", shlvl_str);
	free(shlvl_str);
	if (!new_var)
		fatal_error("Error allocating memory for SHLVL");
	return (new_var);
}

static void	update_existing_shlvl(t_data *data, int i)
{
	int		shlvl;
	char	*new_var;

	shlvl = ft_atoi(data->env[i] + 6);
	new_var = create_shlvl_var(shlvl);
	free(data->env[i]);
	data->env[i] = new_var;
}

static void	increment_shlvl(t_data *data)
{
	int		i;
	char	*new_var;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "SHLVL=", 6) == 0)
		{
			update_existing_shlvl(data, i);
			return ;
		}
		i++;
	}
	new_var = ft_strdup("SHLVL=1");
	if (!new_var)
		fatal_error("Error allocating memory for SHLVL");
	data->env = add_new_env(data->env, new_var);
	free(new_var);
}

void	init_data(t_data *data, char **env)
{
	data->input = NULL;
	data->exit_status = 0;
	data->env = NULL;
	cpy_env(data, env);
	increment_shlvl(data);
	init_expand_data(data);
	init_parser_data(data);
	init_execute_data(data);
}
