/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:49:06 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:39:13 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_tokenizer_error(t_tokenizer_error err)
{
	if (err == TOK_MEMORY_ALLOC)
		ft_putendl_fd("minishell: memory allocation error", 2);
	else if (err == TOK_UNCLOSED_QUOTE)
		ft_putendl_fd("minishell: syntax error: unclosed quote", 2);
	else if (err == TOK_SYNTAX_PIPE)
		ft_putendl_fd("minishell: syntax error near unexpected token `|'",
			2);
	else if (err == TOK_SYNTAX_REDIR)
		ft_putendl_fd("minishell: syntax error near token `<' or `>'", 2);
}

void	ft_expand_error(t_expand_error err)
{
	if (err == EXPAND_MEMORY_ALLOC)
		ft_putendl_fd("minishell: memory allocation error during expansion", 2);
}

void	ft_parser_error(t_parser_error err)
{
	if (err == PARSER_MEMORY_ALLOC)
		ft_putendl_fd("minishell: memory allocation error during parsing", 2);
	else if (err == PARSER_SYNTAX_PIPE)
		ft_putendl_fd("minishell: syntax error near unexpected token `|'",
			2);
	else if (err == PARSER_SYNTAX_REDIR)
		ft_putendl_fd("minishell: syntax error near token `<' or `>'", 2);
}

void	ft_executor_error(t_executor_error err)
{
	if (err == EXECUTOR_FORK_FAIL)
		ft_putendl_fd("minishell: fork failed", 2);
	else if (err == EXECUTOR_PIPE_FAIL)
		ft_putendl_fd("minishell: pipe creation failed", 2);
	else if (err == EXECUTOR_CMD_NOT_FOUND)
		ft_putendl_fd("minishell: command not found", 2);
	else if (err == EXECUTOR_REDIR_FAIL)
		ft_putendl_fd("minishell: failed to open file for redirection", 2);
	else if (err == EXECUTOR_MEMORY_ALLOC)
		ft_putendl_fd("minishell: memory allocation error during execution", 2);
	else if (err == EXECUTOR_DUP_FAIL)
		ft_putendl_fd("minishell: failed to duplicate file descriptor", 2);
}

t_prompt_error	handler_error(t_data *data, t_prompt_error error_type)
{
	if (error_type == ERROR_TOKENIZER)
		ft_tokenizer_error(data->exit_status);
	else if (error_type == ERROR_EXPAND)
		ft_expand_error(data->exit_status);
	else if (error_type == ERROR_PARSER)
		ft_parser_error(data->exit_status);
	else if (error_type == ERROR_EXECUTOR)
		ft_executor_error(data->exit_status);
	free(data->input);
	ft_free_all(data);
	return (PROMPT_CONTINUE);
}
