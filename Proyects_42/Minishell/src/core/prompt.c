/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:07:18 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:37:15 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*get_prompt(void)
{
	static char	prompt[MAX_PROMPT_SIZE];
	char		*username;
	char		cwd[512];

	username = getenv("USER");
	if (!username)
		username = getenv("LOGNAME");
	if (!username)
		username = "guest";
	if (!getcwd(cwd, sizeof(cwd)))
		cwd[0] = '\0';
	build_prompt(prompt, username, cwd);
	return (prompt);
}

static t_prompt_error	handle_parse_error(t_data *data, int status)
{
	if (status == PARSER_HEREDOC_INTERRUPTED)
	{
		ft_free_all(data);
		free(data->input);
		return (PROMPT_CONTINUE);
	}
	data->exit_status = status;
	return (handler_error(data, ERROR_PARSER));
}

static t_prompt_error	process_input(t_data *data)
{
	int	status;

	status = expand_word(data);
	if (status)
	{
		data->exit_status = status;
		return (handler_error(data, ERROR_EXPAND));
	}
	status = tokenizer(data);
	if (status)
	{
		data->exit_status = status;
		return (handler_error(data, ERROR_TOKENIZER));
	}
	status = parser_tokens(data);
	if (status)
		return (handle_parse_error(data, status));
	status = execute(data);
	if (status)
		return (handler_error(data, ERROR_EXECUTOR));
	ft_free_all(data);
	return (PROMPT_CONTINUE);
}

static t_prompt_error	check_exit(t_data *data)
{
	if (ft_strcmp(data->input, "exit") == 0)
	{
		printf("exit\n");
		free(data->input);
		return (PROMPT_EXIT);
	}
	return (PROMPT_CONTINUE);
}

t_prompt_error	init_prompt(t_data *data)
{
	t_prompt_error	result;

	data->input = readline(get_prompt());
	if (g_signal_exit_code != 0)
		data->exit_status = g_signal_exit_code;
	if (!data->input)
	{
		printf("exit\n");
		free(data->input);
		return (PROMPT_EOF);
	}
	if (*data->input != '\0')
		add_history(data->input);
	result = check_exit(data);
	if (result != PROMPT_CONTINUE)
		return (result);
	if (ft_strcmp(data->input, ""))
		return (process_input(data));
	free(data->input);
	if (data->expand.input_expanded)
		free(data->expand.input_expanded);
	return (PROMPT_CONTINUE);
}
