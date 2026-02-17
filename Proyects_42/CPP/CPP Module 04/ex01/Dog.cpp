/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:06:21 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/16 11:46:52 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "[Dog] Constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "[Dog] Copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
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
