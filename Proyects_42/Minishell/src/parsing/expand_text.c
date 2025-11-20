/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:24:22 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/20 10:29:08 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_expand_error	handle_single_quote(t_expand *ex, char *s)
{
	int				start;
	t_expand_error	status;

	ex->i++;
	start = ex->i;
	while (s[ex->i] && s[ex->i] != '\'')
		ex->i++;
	if (ex->i > start)
	{
		status = append_segment(ex, s + start, ex->i - start);
		if (status != EXPAND_OK)
			return (status);
	}
	if (s[ex->i] == '\'')
		ex->i++;
	return (EXPAND_OK);
}

static t_expand_error	dquoted_append_text(t_expand *ex, char *s)
{
	int				start;
	t_expand_error	status;

	start = ex->i;
	while (s[ex->i] && s[ex->i] != '$' && s[ex->i] != '"')
		ex->i++;
	if (ex->i > start)
	{
		status = append_segment(ex, s + start, ex->i - start);
		if (status != EXPAND_OK)
			return (status);
	}
	return (EXPAND_OK);
}

static t_expand_error	handle_dquoted(t_expand *ex, t_data *data, char *s)
{
	t_expand_error	status;

	ex->i++;
	while (s[ex->i] && s[ex->i] != '"')
	{
		if (s[ex->i] == '$')
		{
			status = handle_dollar(data);
			if (status != EXPAND_OK)
				return (status);
		}
		else
		{
			status = dquoted_append_text(ex, s);
			if (status != EXPAND_OK)
				return (status);
		}
	}
	if (s[ex->i] == '"')
		ex->i++;
	return (EXPAND_OK);
}

static t_expand_error	handle_unquoted(t_expand *ex, t_data *data, char *s)
{
	int				start;
	t_expand_error	status;

	start = ex->i;
	while (s[ex->i] && s[ex->i] != '$' && s[ex->i] != '\'' && s[ex->i] != '"')
		ex->i++;
	if (ex->i > start)
	{
		status = append_segment(ex, s + start, ex->i - start);
		if (status != EXPAND_OK)
			return (status);
	}
	if (s[ex->i] == '$')
	{
		status = handle_dollar(data);
		if (status != EXPAND_OK)
			return (status);
	}
	return (EXPAND_OK);
}

t_expand_error	process_text_and_vars(t_data *data)
{
	t_expand_error	status;
	char			*s;

	s = data->expand.input;
	while (s[data->expand.i])
	{
		if (s[data->expand.i] == '\'')
		{
			status = handle_single_quote(&data->expand, s);
			if (status != EXPAND_OK)
				return (status);
			continue ;
		}
		if (s[data->expand.i] == '"')
		{
			status = handle_dquoted(&data->expand, data, s);
			if (status != EXPAND_OK)
				return (status);
			continue ;
		}
		status = handle_unquoted(&data->expand, data, s);
		if (status != EXPAND_OK)
			return (status);
	}
	return (EXPAND_OK);
}
