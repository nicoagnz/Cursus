/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:33:17 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:47 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_redirect_out(t_tokenizer *tokenizer)
{
	if (!tokenizer->tokens || tokenizer->tokens->type == TOKEN_PIPE)
		return (TOK_SYNTAX_REDIR);
	if (*(tokenizer->end + 1) == '>')
	{
		add_token(&tokenizer->tokens, create_token(">>", TOKEN_REDIR_APPEND));
		tokenizer->end += 2;
	}
	else
	{
		add_token(&tokenizer->tokens, create_token(">", TOKEN_REDIR_OUT));
		tokenizer->end++;
	}
	if (*tokenizer->end == '\0')
		return (TOK_SYNTAX_REDIR);
	tokenizer->start = tokenizer->end;
	return (TOK_OK);
}

int	handle_redirect_in(t_tokenizer *tokenizer)
{
	if (!tokenizer->tokens || tokenizer->tokens->type == TOKEN_PIPE)
		return (TOK_SYNTAX_REDIR);
	if (*(tokenizer->end + 1) == '<')
	{
		add_token(&tokenizer->tokens, create_token("<<", TOKEN_HEREDOC));
		tokenizer->end += 2;
	}
	else
	{
		add_token(&tokenizer->tokens, create_token("<", TOKEN_REDIR_IN));
		tokenizer->end++;
	}
	if (*tokenizer->end == '\0')
		return (TOK_SYNTAX_REDIR);
	tokenizer->start = tokenizer->end;
	return (TOK_OK);
}

int	handle_pipe(t_tokenizer *tokenizer)
{
	if (!tokenizer->tokens || tokenizer->tokens->type == TOKEN_PIPE)
		return (TOK_SYNTAX_PIPE);
	tokenizer->end++;
	if (*tokenizer->end == '\0')
		return (TOK_SYNTAX_PIPE);
	add_token(&tokenizer->tokens, create_token("|", TOKEN_PIPE));
	tokenizer->start = tokenizer->end;
	return (TOK_OK);
}

int	handle_quote(t_tokenizer *tokenizer, char quote)
{
	char	*value;

	tokenizer->end++;
	while (*tokenizer->end && *tokenizer->end != quote)
		tokenizer->end++;
	if (*tokenizer->end != quote)
	{
		tokenizer->start = tokenizer->end;
		return (TOK_UNCLOSED_QUOTE);
	}
	value = ft_strndup(tokenizer->start + 1,
			tokenizer->end - tokenizer->start - 1);
	if (!value)
	{
		tokenizer->start = tokenizer->end;
		return (TOK_MEMORY_ALLOC);
	}
	if (quote == '\'')
		add_token(&tokenizer->tokens, create_token(value, TOKEN_QUOTE_SINGLE));
	else
		add_token(&tokenizer->tokens, create_token(value, TOKEN_QUOTE_DOUBLE));
	free(value);
	tokenizer->end++;
	tokenizer->start = tokenizer->end;
	return (TOK_OK);
}

t_tokenizer_error	tokenizer(t_data *data)
{
	t_tokenizer_error	status;

	if (!data)
		return (TOK_MEMORY_ALLOC);
	init_tokenizer_data(data);
	if (!data->tokenizer.input_to_tokenize)
		return (TOK_MEMORY_ALLOC);
	while (*data->tokenizer.start)
	{
		while (*data->tokenizer.start && ft_isspace(*data->tokenizer.start))
			data->tokenizer.start++;
		if (!*data->tokenizer.start)
			break ;
		data->tokenizer.end = data->tokenizer.start;
		status = process_token(data);
		if (status)
			return (status);
	}
	add_token(&data->tokenizer.tokens, create_token(NULL, TOKEN_EOF));
	return (TOK_OK);
}
