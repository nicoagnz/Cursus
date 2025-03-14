
#include <unistd.h>

int main(int ac, char **av)
{
	if(ac == 2)
	{
		int i = 0, space = 0;
		while(av[1][i] == ' ')
			i++;
		while(av[1][i])
		{
			if(av[1][i] == ' ')
				space = 1;
			if(av[1][i] != ' ')
			{
				if(space == 1)
					write(1, " ", 1);
				space = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}

