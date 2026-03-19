#include <unistd.h>
#include <stdlib.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	int p[2], pid;

	if (!file || !argv || (type != 'r' && type != 'w') || pipe(p) == -1)
		return (-1);
	if ((pid = fork()) == -1)
		return (-1);
	if (!pid)
	{
		dup2(p[type == 'r'], type == 'r');
		close(p[0]);
		close(p[1]);
		execvp(file, argv);
		exit(1);
	}
	close(p[type == 'r']);
	return (p[type != 'r']);
}
