/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:28:10 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/20 10:28:27 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_expand_error	expand_word(t_data *data)
{
	t_expand_error	status;

	init_expand(data);
	if (!data->expand.result)
		return (EXPAND_MEMORY_ALLOC);
	status = process_text_and_vars(data);
	if (status != EXPAND_OK)
		return (status);
	data->expand.input_expanded = data->expand.result;
	return (EXPAND_OK);
}
