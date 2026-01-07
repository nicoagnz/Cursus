#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "[Cat] Constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "[Cat] Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "[Cat] Copy assignment called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "[Cat] Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] Meow Meow!" << std::endl;
}
