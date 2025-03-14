/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 09:39:52 by nacuna-g          #+#    #+#             */
/*   Updated: 2025/03/14 11:13:27 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	*files;
	int	pipefd[2];
	pid_t	pid;
	int status;

	if (ac != 5)
		error_exit(0, "Error: Wrong number of arguments\n", NULL, NULL);
	files = open_files(av[1], av[4]);
	if (pipe(pipefd) == -1)
		error_exit(0, "pipe", NULL, NULL);
	pid = fork();
	if (pid == -1)
		error_exit(0, "fork failed", NULL, NULL);
	else if (pid == 0)
	{
		first_child(av[2], files[0], pipefd, env);
	}
	else
	{
		status = parent(pid, av, env, files, pipefd);
	}
	close(files[0]);
	close(files[1]);
	close(pipefd[0]);
	close(pipefd[1]);
	wait(NULL);
	wait(NULL);
	free(files);
	return (status);
}


int parent(pid_t pid1, char **av, char **env, int *files, int *pipefd)
{
	pid_t	pid2;
	int		status;

	pid2 = fork();
	if (pid2 == -1)
		error_exit(0, "fork failed", NULL, NULL);
	else if (pid2 == 0)
	{
		second_child(av[2], files[0], pipefd, env);
	}
	else
	{
		close(pipefd[0]);
		close(pipefd[1]);
		
		waitpid(pid1, &status, 0);
		if (WEXITSTATUS(status) != 0)
		{
			exit(EXIT_FAILURE);
		}
		waitpid(pid2, &status, 0);
		if(WEXITSTATUS(status) != 0)
		{
			exit(EXIT_FAILURE);
		}
	}
	return (status);
}

void	first_child(char *cmd, int in_file, int *pipefd, char **env)
{
	int		pid;
	char	**args;
	char	*cmd_path;

	pid = fork();
	if (pid == -1)
		error_exit(0, "fork failed", NULL, NULL);
	if (pid == 0)
	{
		args = div_command(cmd);
		cmd_path = get_full_path(args[0], env);
		if (!cmd_path)
			error_exit(1, cmd, args, NULL);
		first_child_setup(pipefd, in_file);
		if (execve(cmd_path, args, env) == -1)
		{
			free(cmd_path);
			free(args);
			error_exit(2, cmd, args, cmd_path);
		}
		free(cmd_path);
		free(args);
	}
}

void	second_child(char *cmd, int out_file, int *pipefd, char **env)
{
	int		pid;
	char	**args;
	char	*cmd_path;


	pid = fork();
	if (pid == -1)
		error_exit(0, "fork failed", NULL, NULL);
	if (pid == 0)
	{
		args = div_command(cmd);
		cmd_path = get_full_path(args[0], env);
		if (!cmd_path)
			error_exit(1, cmd, args, NULL);
		second_child_setup(pipefd, out_file);
		if (execve(cmd_path, args, env) == -1)
		{
			free(cmd_path);
			free(args);
			printf("execve failed\n");
			exit(EXIT_FAILURE);
			error_exit(2, cmd, args, cmd_path);
		}
		free(cmd_path);
		free(args);
	}

}

void	first_child_setup(int *pipefd, int in_file)
{
	close(pipefd[0]);
	dup2(in_file, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(in_file);
	close(pipefd[1]);
}

void	second_child_setup(int *pipefd, int out_file)
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(out_file, STDOUT_FILENO);
	close(pipefd[0]);
	close(out_file);
}
