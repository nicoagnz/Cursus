/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:06:23 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/16 11:46:01 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const int size = 4;
	Animal* animals[size];

	std::cout << "=== Creating animals ===" << std::endl;
	int i = 0;
	while (i < size / 2)
	{
		animals[i] = new Dog();
		i++;
	}
	while (i < size)
	{
		animals[i] = new Cat();
		i++;
	}

	std::cout << "\n=== Deleting animals ===" << std::endl;
	i = 0;
	while (i < size)
	{
		delete animals[i];
		i++;
	}

	std::cout << "\n=== Checking copies ===" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	Cat originalCat;
	Cat copiedCat(originalCat);

	std::cout << "\n=== Destroying copies ===" << std::endl;

	return 0;
}
