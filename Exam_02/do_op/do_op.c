
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if(ac == 4)
	{
		switch(av[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '-':
				printf("%d", atoi(av[1]) - atoi(av[3]));
				break;
			case '*':
				printf("%d", atoi(av[1]) * atoi(av[3]));
				break;
			case '/':
				printf("%d", atoi(av[1]) / atoi(av[3]));
				break;
			case '%':
				printf("%d", atoi(av[1]) % atoi(av[3]));
				break;
		}
	}
	printf("\n");
	return (0);
}

