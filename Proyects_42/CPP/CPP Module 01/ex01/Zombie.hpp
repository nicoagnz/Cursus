#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void setName(std::string name);
	void announce(void);
};

Zombie* zombieHorde(int n, std::string name);

#endif