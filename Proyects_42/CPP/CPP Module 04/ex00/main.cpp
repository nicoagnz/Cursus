/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:03:06 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/16 10:49:39 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== Polymorphism Test ==========" << std::endl;
	std::cout << "\n---- Constructors ----" << std::endl;
	const Animal* baseAnimal = new Animal();
	const Animal* dogAnimal = new Dog();
	const Animal* catAnimal = new Cat();

	std::cout << "\n---- Types ----" << std::endl;
	std::cout << dogAnimal->getType() << std::endl;
	std::cout << catAnimal->getType() << std::endl;

	std::cout << "\n---- Sounds ----" << std::endl;
	dogAnimal->makeSound();
	catAnimal->makeSound();
	baseAnimal->makeSound();

	std::cout << "\n---- Destructors ----" << std::endl;
	delete baseAnimal;
	delete dogAnimal;
	delete catAnimal;

	std::cout << "\n========== Wrong (no virtual) test ==========" << std::endl;
	std::cout << "\n---- Constructors ----" << std::endl;
	const WrongAnimal* wrongBase = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "\n---- Types ----" << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	std::cout << "\n---- Sounds ----" << std::endl;
	wrongCat->makeSound();
	wrongBase->makeSound();

	std::cout << "\n---- Destructors ----" << std::endl;
	delete wrongBase;
	delete wrongCat;

	return 0;
}
