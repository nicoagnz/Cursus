#include "Zombie.hpp"

Zombie::Zombie() : name ("")
{
	std::cout << "A zombie has been created" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << name << " has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl;
}

void Zombie::setName(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
