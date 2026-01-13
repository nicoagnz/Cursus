#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	picoshell(char **cmds[])
{
	int i = 0, in = 0, ret = 0, fd[2], status;

	while (cmds[i])
	{
		pipe(fd);
		if (!fork())
		{
			dup2(in, 0);
			if (cmds[i + 1])
				dup2(fd[1], 1);
			if (in)
				close(in);
			close(fd[0]);
			close(fd[1]);
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		close(fd[1]);
		if (in)
			close(in);
		in = fd[0];
		i++;
	}
	if (in)
		close(in);
	while (wait(&status) > 0)
		if (status)
			ret = 1;
	return (ret);
}

