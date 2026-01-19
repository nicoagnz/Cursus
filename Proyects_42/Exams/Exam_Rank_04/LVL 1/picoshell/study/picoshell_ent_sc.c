#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int picoshell(char ***cmds)
{
	int i = 0;
	int input_fd = 0;
	int pipefd[2];
	int status;
	int error = 0;

	while (cmds[i] != NULL)
	{
		pipe(pipefd);
		pid_t pid = fork();
		if (pid == 0)
		{
			dup2(input_fd, STDIN_FILENO);
			if (cmds[i + 1] != NULL)
				dup2(pipefd[1], STDOUT_FILENO);
			if (input_fd != 0)
				close(input_fd);
			close(pipefd[0]);
			close(pipefd[1]);
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		close(pipefd[1]);
		if (input_fd != 0)
			close(input_fd);
		input_fd = pipefd[0];
		i++;
	}
	if (input_fd != 0)
		close(input_fd);
	while (wait(&status) > 0)
	{
		if (status != 0)
			error = 1;
	}
	return error;
}

