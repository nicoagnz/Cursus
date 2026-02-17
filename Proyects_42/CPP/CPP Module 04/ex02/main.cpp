/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:06:37 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/17 10:28:00 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const int size = 6;
	AAnimal* animals[size];

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

	std::cout << "\n=== Copy tests ===" << std::endl;
	Dog originalDog;
	Dog copiedDog(originalDog);
	Cat originalCat;
	Cat copiedCat(originalCat);

	std::cout << "\n=== Destroying copies ===" << std::endl;



	return 0;
}

// 	std::cout << "\n=== Abstract class test ===" << std::endl;
//	AAnimal test;
//	AAnimal* test2 = new AAnimal();
