#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	if (n <= 0)
		return NULL;
	Zombie* horde = new Zombie[n];
	int i = 0;
	while (i < n)
	{
		horde[i].setName(name);
		i++;
	}
	return horde;
}
