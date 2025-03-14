#include <stdlib.h>
#include <stdio.h>

static void	ft_prime(int number)
{
	unsigned int	prime;

	if (number == 1)
		printf("1");
	else
	{
		prime = 2;
		while (prime <= number)
		{
			if ((number % prime) == 0)
			{
				printf("%d", prime);
				if (number != prime)
					printf("*");
				number /= prime;
			}
			else
				prime++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_prime(atoi(argv[1]));
	printf("\n");
	return (EXIT_SUCCESS);
}

