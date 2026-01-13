#include <unistd.h>
#include <stdlib.h>


int ft_popen(const char *file, char *const argv[], char type)
{
	int pipefd[2];
	if (!file || !argv || (type != 'r' && type != 'w') || pipe(pipefd) || fork())
		;
	else
	{
		dup2(pipefd[type == 'r'], type == 'r' ? 1 : 0);
		close(pipefd[0]);
		close(pipefd[1]);
		execvp(file, argv);
		exit(1);
	}
	close(pipefd[type == 'r']);
	return (pipefd[type != 'r']);
}

