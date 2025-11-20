/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_tokenizer2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:00:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:39:02 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_tokenizer_data(t_data *data)
{
	if (data->expand.input_expanded)
		data->tokenizer.input_to_tokenize = data->expand.input_expanded;
	else
		data->tokenizer.input_to_tokenize = data->input;
	data->tokenizer.start = data->tokenizer.input_to_tokenize;
	data->tokenizer.end = data->tokenizer.input_to_tokenize;
	data->tokenizer.tokens = NULL;
}

int	handle_word(t_tokenizer *tokenizer)
{
	char	*value;

	while (*tokenizer->end && !ft_isspace(*tokenizer->end)
		&& *tokenizer->end != '\'' && *tokenizer->end != '"'
		&& *tokenizer->end != '|' && *tokenizer->end != '<'
		&& *tokenizer->end != '>')
		tokenizer->end++;
	if (tokenizer->end > tokenizer->start)
	{
		value = ft_strndup(tokenizer->start, tokenizer->end - tokenizer->start);
		if (!value)
			return (TOK_MEMORY_ALLOC);
		add_token(&tokenizer->tokens, create_token(value, TOKEN_WORD));
		free(value);
	}
	tokenizer->start = tokenizer->end;
	return (TOK_OK);
}

int	process_token(t_data *data)
{
	if (*data->tokenizer.end == '\'' || *data->tokenizer.end == '"')
		return (handle_quote(&data->tokenizer, *data->tokenizer.end));
	else if (*data->tokenizer.end == '|')
		return (handle_pipe(&data->tokenizer));
	else if (*data->tokenizer.end == '>')
		return (handle_redirect_out(&data->tokenizer));
	else if (*data->tokenizer.end == '<')
		return (handle_redirect_in(&data->tokenizer));
	else
		return (handle_word(&data->tokenizer));
}
