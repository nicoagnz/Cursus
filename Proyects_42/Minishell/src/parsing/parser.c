/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:55:42 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:45 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_parser_error	parser_tokens(t_data *data)
{
	data->parser.tokens = data->tokenizer.tokens;
	init_parser(&data->parser, data->parser.tokens);
	return (process_tokens(data));
}
