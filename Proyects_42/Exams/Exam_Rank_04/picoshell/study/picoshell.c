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

====================================================================

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int pipefd[2];
	int in = 0;
	int status;
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) == -1)
			return 1;
		if ((pid = fork) < 0)
			return 1;
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
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) > 0)
		;
	return 0;
}

====================================================================

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int pipefd[2];
	int i = 0;
	int in = 0;
	int status;
	pid_t pid;

	while(cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) < 0)
			return 1;
		if ((pid = fork()) < 0)
			return 1;
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmd[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) > 0);
	return 0;
}

================================================================

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int pipefd[2];
	int i = 0;
	int in = 0;
	int status;
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) < 0)
			return 1;
		if ((pid = fork()) < 0)
			return 1;
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmds[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) > 0);
	return 0;
}

===============================================================

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int in = 0;
	int pipefd[2];
	int status;
	pid_t pid;

	while (cmds[i])
	{

		if (cmds[i + 1] && pipe(pipefd) < 0)
			return 1;
		if ((pid= fork()) < 0)
			return 1;
		if (in)
			close(in);
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmds[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) < 0);
	return 0;
}

================================================================

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int in = 0;
	int status;
	int pipefd[2];
	pid_t pid;

	while(cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) < 0)
			return 1;
		if ((pid = fork()) < 0)
			return 1;
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmds[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) < 0);
	return 0;
}

=====================================================================

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int in = 0;
	int status;
	int pipefd[2];
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) < 0)
			return 1;
		if ((pid = fork()) < 0)
			return 1;
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmd[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) < 0);
	return 0;
}

=============================================================================

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int in = 0;
	int status;
	int pipefd[2];
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) < 0)
			exit(1);
		if ((pid = fork()) < 0)
			exit(1);
		if(!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmds[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) < 0);
	return 0;
}

=================================================================

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int in = 0;
	int status;
	int pipefd[2];
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) < 0)
			return 1;
		if ((pid = fork()) < 0)
			return 1;
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmds[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) < 0);
	return 0;
}

===================================================================

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int status;
	int in = 0;
	int pipefd[2];
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1], pipe(pipefd) < 0)
			return 1;
		if ((pid = fork()) < 0)
			return 1;
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmds[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) < 0);
	return 0;
}

===============================================================================

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int i = 0;
	int in = 0;
	int status;
	int pipefd[2];
	pid_t pid;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(pipefd) < 0)
			return 1;
		if ((pid = fork()) < 0)
			return 1;
		if (!pid)
		{
			if (dup2(in, 0) < 0)
				exit(1);
			if (cmds[i + 1] && dup2(pipefd[1], 1) < 0)
				exit(1);
			if (in)
				close(in);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i + 1], cmds[i]);
			exit(1);
		}
		if (in)
			close(in);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			in = pipefd[0];
		}
		i++;
	}
	while (wait(&status) < 0);
	return (0);
}

