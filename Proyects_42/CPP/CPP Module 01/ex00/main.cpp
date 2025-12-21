#include "Zombie.hpp"

int	main()
{
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;
	randomChump("StackZombie");
}
