/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:03:06 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/12 12:03:07 by nacuna-g         ###   ########.fr       */
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

	const Animal* baseAnimal = new Animal();
	const Animal* dogAnimal = new Dog();
	const Animal* catAnimal = new Cat();

	std::cout << dogAnimal->getType() << std::endl;
	std::cout << catAnimal->getType() << std::endl;

	dogAnimal->makeSound();
	catAnimal->makeSound();
	baseAnimal->makeSound();

	delete baseAnimal;
	delete dogAnimal;
	delete catAnimal;

	std::cout << "\n========== Wrong (no virtual) test ==========" << std::endl;
	const WrongAnimal* wrongBase = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	wrongBase->makeSound();

	delete wrongBase;
	delete wrongCat;

	return 0;
}
