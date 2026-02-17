/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:03:02 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/16 10:20:45 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "[Dog] Guau Guau!" << std::endl;
}
