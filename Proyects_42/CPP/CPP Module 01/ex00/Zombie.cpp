#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
