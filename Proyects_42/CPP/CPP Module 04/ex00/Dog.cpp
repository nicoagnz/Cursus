#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "[Dog] Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "[Dog] Copy assignment called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "[Dog] Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof Woof!" << std::endl;
}
