/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:06:31 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/16 11:27:46 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "[Brain] Default constructor called" << std::endl;
	int i = 0;
	while (i < 100)
	{
		ideas[i] = "";
		i++;
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "[Brain] Copy constructor called" << std::endl;
	int i = 0;
	while (i < 100)
	{
		ideas[i] = other.ideas[i];
		i++;
	}
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other)
	{
		int i = 0;
		while (i < 100)
		{
			ideas[i] = other.ideas[i];
			i++;
		}
	}
	std::cout << "[Brain] Copy assignment called" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "[Brain] Destructor called" << std::endl;
}
