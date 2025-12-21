#include "Zombie.hpp"

int	main()
{
	int N = 5;
	int i = 0;

	Zombie* horde = zombieHorde(5, "Hordezombie");
	if (!horde)
		return 1;
	while (i < N)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return 0;
}
