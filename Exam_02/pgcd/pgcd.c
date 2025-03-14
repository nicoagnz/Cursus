#include <stdlib.h>
#include <stdio.h>

static void	ft_pgcd(int nbr_1, int nbr_2);

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (EXIT_SUCCESS);
}

static void	ft_pgcd(int nbr_1, int nbr_2)
{
	int	div;
	int	pgcd;

	div = 1;
	if (nbr_1 <= 0 || nbr_2 <= 0)
		return ;
	while ((div <= nbr_1) || (div <= nbr_2))
	{
		if (((nbr_1 % div) == 0) && ((nbr_2 % div) == 0))
			pgcd = div;
		div++;
	}
	printf("%d", pgcd);
}

