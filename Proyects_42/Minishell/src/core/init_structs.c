/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:00:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/17 12:00:00 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	fatal_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(EXIT_FAILURE);
}

void	cpy_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 1));
	if (!data->env)
		fatal_error("Error allocating memory for env");
	i = 0;
	while (env[i])
	{
		data->env[i] = ft_strdup(env[i]);
		if (!data->env[i])
			fatal_error("Error duplicating env string");
		i++;
	}
	data->env[i] = NULL;
}

void	init_expand_data(t_data *data)
{
	data->expand.result = NULL;
	data->expand.var = NULL;
	data->expand.value = NULL;
	data->expand.i = 0;
	data->expand.start = 0;
	data->expand.input = NULL;
	data->expand.input_expanded = NULL;
	data->expand.env = data->env;
	data->expand.exit_status = 0;
}

void	init_parser_data(t_data *data)
{
	data->tokenizer.start = NULL;
	data->tokenizer.end = NULL;
	data->tokenizer.input_to_tokenize = NULL;
	data->tokenizer.tokens = NULL;
	data->parser.current = NULL;
	data->parser.head = NULL;
	data->parser.cmd = NULL;
	data->parser.tokens = NULL;
	data->parser.cmds_list = NULL;
}

void	init_execute_data(t_data *data)
{
	data->execute.cmds_list = NULL;
	data->execute.env = data->env;
	data->execute.exit_status = 0;
	data->execute.last_pid = 0;
	data->execute.pipe_fds[0] = 0;
	data->execute.pipe_fds[1] = 0;
	data->execute.in_fd = 0;
}
