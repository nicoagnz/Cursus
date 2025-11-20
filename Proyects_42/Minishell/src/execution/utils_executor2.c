/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executor2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:00:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:31 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_executor_error	handle_redir_in(t_cmd *cmd)
{
	int	fd;

	if (!cmd->redir_in)
		return (EXECUTOR_OK);
	fd = open(cmd->redir_in, O_RDONLY);
	if (fd == -1)
		return (EXECUTOR_REDIR_FAIL);
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		return (EXECUTOR_DUP_FAIL);
	}
	close(fd);
	return (EXECUTOR_OK);
}

t_executor_error	handle_redir_out(t_cmd *cmd)
{
	int	fd;

	if (!cmd->redir_out)
		return (EXECUTOR_OK);
	if (cmd->is_append)
		fd = open(cmd->redir_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(cmd->redir_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (EXECUTOR_REDIR_FAIL);
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		return (EXECUTOR_DUP_FAIL);
	}
	close(fd);
	return (EXECUTOR_OK);
}

t_executor_error	handle_redirections(t_cmd *cmd)
{
	t_executor_error	err;

	err = handle_redir_in(cmd);
	if (err != EXECUTOR_OK)
		return (err);
	err = handle_redir_out(cmd);
	return (err);
}

int	handle_builtin_no_redir(t_data *data, t_cmd *cmd)
{
	if (cmd->av && cmd->av[0] && is_builtin(cmd->av[0]))
	{
		if (!cmd->redir_in && !cmd->redir_out)
		{
			exec_builtin(data, cmd);
			data->execute.exit_status = data->exit_status;
			return (1);
		}
	}
	return (0);
}

void	exec_child_process(t_data *data, t_cmd *cmd)
{
	char				*path;
	t_executor_error	err;

	setup_child_signals();
	err = handle_redirections(cmd);
	if (err != EXECUTOR_OK)
	{
		if (cmd->redir_in)
			handler_error_child(CHILD_REDIR_FAIL, cmd->redir_in);
		else
			handler_error_child(CHILD_REDIR_FAIL, cmd->redir_out);
	}
	path = find_command_path(cmd->av[0], data->env);
	if (!path)
		handler_error_child(CHILD_CMD_NOT_FOUND, cmd->av[0]);
	execve(path, cmd->av, data->env);
	free(path);
	handler_error_child(CHILD_EXEC_FAIL, cmd->av[0]);
}
