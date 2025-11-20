/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_executor3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:10:00 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/11/19 11:38:35 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_wait_status(t_data *data, int status)
{
	if (WIFEXITED(status))
		data->execute.exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_signal_exit_code = 128 + WTERMSIG(status);
		if (WTERMSIG(status) == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		else if (WTERMSIG(status) == SIGQUIT)
			write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	}
	else if (WIFSTOPPED(status))
	{
		g_signal_exit_code = 128 + WSTOPSIG(status);
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "[1]+  Stopped\n", 15);
	}
	else
		data->execute.exit_status = 1;
}

static void	exec_pipe_cmd(t_data *data, t_cmd *cmd)
{
	char	*path;

	if (!cmd->av || !cmd->av[0])
		exit(127);
	if (is_builtin(cmd->av[0]))
	{
		exec_builtin(data, cmd);
		exit(0);
	}
	path = find_command_path(cmd->av[0], data->env);
	if (!path)
		exit(127);
	execve(path, cmd->av, data->env);
	free(path);
	exit(1);
}

void	exec_pipe_child(t_data *data, t_cmd *cmd, int in_fd, int fd[2])
{
	t_executor_error	err;

	setup_child_signals();
	if (in_fd != 0 && dup2(in_fd, STDIN_FILENO) == -1)
		exit(EXECUTOR_DUP_FAIL);
	if (cmd->next && dup2(fd[1], STDOUT_FILENO) == -1)
		exit(EXECUTOR_DUP_FAIL);
	err = handle_redirections(cmd);
	if (err != EXECUTOR_OK)
		exit(err);
	if (cmd->next)
	{
		close(fd[0]);
		close(fd[1]);
	}
	exec_pipe_cmd(data, cmd);
}

void	handle_last_pid_status(t_data *data, pid_t pid, pid_t last, int wst)
{
	if (pid != last)
		return ;
	if (WIFEXITED(wst))
		data->execute.exit_status = WEXITSTATUS(wst);
	else if (WIFSIGNALED(wst))
	{
		g_signal_exit_code = 128 + WTERMSIG(wst);
		if (WTERMSIG(wst) == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		else if (WTERMSIG(wst) == SIGQUIT)
			write(STDOUT_FILENO, "Quit (core dumped)\n", 19);
	}
	else if (WIFSTOPPED(wst))
	{
		g_signal_exit_code = 128 + WSTOPSIG(wst);
		write(STDOUT_FILENO, "\n", 1);
		write(STDOUT_FILENO, "[1]+  Stopped\n", 15);
	}
}
