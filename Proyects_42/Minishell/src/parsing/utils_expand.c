/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:29:25 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:39:31 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_expand(t_data *data)
{
	data->expand.input = data->input;
	data->expand.env = data->env;
	data->expand.exit_status = data->exit_status;
	data->expand.result = ft_strdup("");
	data->expand.var = NULL;
	data->expand.value = NULL;
	data->expand.i = 0;
	data->expand.start = 0;
	data->expand.input_expanded = NULL;
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

t_expand_error	append_segment(t_expand *ex, char *start, int len)
{
	char	*segment;
	char	*tmp;

	segment = ft_strndup(start, len);
	if (!segment)
		return (EXPAND_MEMORY_ALLOC);
	tmp = ft_strjoin_free(ex->result, segment);
	free(segment);
	if (!tmp)
		return (EXPAND_MEMORY_ALLOC);
	ex->result = tmp;
	return (EXPAND_OK);
}

t_expand_error	handle_dollar(t_data *data)
{
	data->expand.i++;
	if (data->expand.input[data->expand.i] == '\0'
		|| data->expand.input[data->expand.i] == ' ')
	{
		data->expand.result = ft_strjoin_free(data->expand.result, "$");
		if (!data->expand.result)
			return (EXPAND_MEMORY_ALLOC);
	}
	else
		return (expand_variable(data));
	return (EXPAND_OK);
}
