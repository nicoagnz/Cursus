/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:03:16 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/02/16 10:48:18 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "[WrongCat] Constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] Destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] Miau?" << std::endl;
}
