/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:12:21 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:23 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static t_executor_error	exec_single(t_data *data, t_cmd *cmd)
{
	pid_t	pid;
	int		status;

	if (handle_builtin_no_redir(data, cmd))
		return (EXECUTOR_OK);
	if (!cmd->av || !cmd->av[0])
	{
		data->execute.exit_status = 127;
		return (EXECUTOR_CMD_NOT_FOUND);
	}
	setup_exec_signals();
	pid = fork();
	if (pid == -1)
	{
		setup_signals();
		return (EXECUTOR_FORK_FAIL);
	}
	if (pid == 0)
		exec_child_process(data, cmd);
	waitpid(pid, &status, WUNTRACED);
	setup_signals();
	handle_wait_status(data, status);
	return (EXECUTOR_OK);
}

static t_executor_error	do_pipeline_fork(t_data *data, t_cmd **cmd,
									int *in_fd, int fd[2])
{
	pid_t	pid;

	if ((*cmd)->next && pipe(fd) == -1)
	{
		setup_signals();
		return (EXECUTOR_PIPE_FAIL);
	}
	pid = fork();
	if (pid == -1)
	{
		setup_signals();
		return (EXECUTOR_FORK_FAIL);
	}
	if (pid == 0)
		exec_pipe_child(data, *cmd, *in_fd, fd);
	if (*in_fd != 0)
		close(*in_fd);
	if ((*cmd)->next)
	{
		close(fd[1]);
		*in_fd = fd[0];
	}
	*cmd = (*cmd)->next;
	return (pid);
}

static t_executor_error	exec_pipeline(t_data *data, t_cmd *cmd)
{
	int		fd[2];
	int		in_fd;
	pid_t	pid;
	pid_t	last_pid;
	int		wstatus;

	in_fd = 0;
	setup_exec_signals();
	while (cmd)
	{
		pid = do_pipeline_fork(data, &cmd, &in_fd, fd);
		if (pid < 0)
			return (pid);
		last_pid = pid;
	}
	pid = waitpid(-1, &wstatus, WUNTRACED);
	while (pid > 0)
	{
		handle_last_pid_status(data, pid, last_pid, wstatus);
		pid = waitpid(-1, &wstatus, WUNTRACED);
	}
	setup_signals();
	if (data->execute.exit_status == 0)
		data->execute.exit_status = 1;
	return (EXECUTOR_OK);
}

t_executor_error	execute(t_data *data)
{
	t_executor_error	status;

	status = EXECUTOR_OK;
	data->execute.cmds_list = data->parser.cmds_list;
	data->execute.env = data->env;
	data->execute.exit_status = data->exit_status;
	data->execute.in_fd = 0;
	if (!data->execute.cmds_list)
		return (EXECUTOR_OK);
	if (!data->execute.cmds_list->next)
		status = exec_single(data, data->execute.cmds_list);
	else
		status = exec_pipeline(data, data->execute.cmds_list);
	update_exit_status(data);
	return (status);
}
