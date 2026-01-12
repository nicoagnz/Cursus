/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:06:23 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/12 12:06:24 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== Exercise 01 Test ==========" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; 
	delete i;

	const int SIZE = 6;
	Animal* zoo[SIZE];
	for (int k = 0; k < SIZE; ++k)
	{
		if (k < SIZE / 2)
			zoo[k] = new Dog();
		else
			zoo[k] = new Cat();
	}

	for (int k = 0; k < SIZE; ++k)
	{
		std::cout << zoo[k]->getType() << std::endl;
		zoo[k]->makeSound();
	}

	for (int k = 0; k < SIZE; ++k)
		delete zoo[k]; 

	std::cout << "\n-- Deep copy test --" << std::endl;
	Dog* dog1 = new Dog();
	dog1->getBrain()->ideas[0] = "Chase the ball";
	Dog* dog2 = new Dog(*dog1); 
	std::cout << "dog1 idea[0]: " << dog1->getBrain()->ideas[0] << std::endl;
	std::cout << "dog2 idea[0]: " << dog2->getBrain()->ideas[0] << std::endl;

	dog1->getBrain()->ideas[0] = "Sleep now";
	std::cout << "after change dog1 idea[0]: " << dog1->getBrain()->ideas[0] << std::endl;
	std::cout << "after change dog2 idea[0]: " << dog2->getBrain()->ideas[0] << std::endl;

	delete dog1;
	delete dog2;

	return 0;
}
