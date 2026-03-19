#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	picoshell(char **cmds[])
{
	int		i = 0, fd[2], in = 0;
	pid_t	pid;
	int		status;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)
		{
			if (dup2(in, 0) == -1)
				exit(1);
			if (cmds[i + 1] && dup2(fd[1], 1) == -1)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(fd[1]);
			in = fd[0];
		}
		i++;
	}
	while (wait(&status) > 0)
		;
	return (0);
}
