#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "[Dog] Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		if (brain)
			delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "[Dog] Copy assignment called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "[Dog] Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] Woof Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}
