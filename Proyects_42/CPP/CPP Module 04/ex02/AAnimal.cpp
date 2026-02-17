/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:06:29 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/17 10:21:51 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal")
{
	std::cout << "[AAnimal] Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other): type(other.type)
{
	std::cout << "[AAnimal] Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << "[AAnimal] Copy assignment called" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] Destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}
