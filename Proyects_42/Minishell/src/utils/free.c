/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 12:45:38 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:39:16 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	while (cmd)
	{
		tmp = cmd->next;
		if (cmd->av)
		{
			i = 0;
			while (cmd->av[i])
				free(cmd->av[i++]);
			free(cmd->av);
		}
		free(cmd->redir_in);
		free(cmd->redir_out);
		free(cmd->heredoc_delim);
		free(cmd);
		cmd = tmp;
	}
}

void	free_tokens(t_token *tokens)
{
	t_token	*current;
	t_token	*next;

	current = tokens;
	while (current)
	{
		next = current->next;
		free(current->value);
		free(current);
		current = next;
	}
}

void	ft_free_all(t_data *data)
{
	if (data->tokenizer.tokens)
		free_tokens(data->tokenizer.tokens);
	if (data->parser.cmds_list)
		free_cmds(data->parser.cmds_list);
	if (data->expand.input_expanded)
		free(data->expand.input_expanded);
	data->tokenizer.tokens = NULL;
	data->parser.cmds_list = NULL;
	data->expand.input_expanded = NULL;
	data->execute.cmds_list = NULL;
}

void	free_array(char **array)
{
	int	i;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
