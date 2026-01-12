/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:19:26 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/12 13:02:04 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

bool Contact::setInfo()
{
	std::string input;
	std::cout << "First name: ";
	if (!std::getline(std::cin, input)) return false;
		firstName = input;
	std::cout << "Last name: ";
	if (!std::getline(std::cin, input)) return false;
		lastName = input;
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, input)) return false;
		nickname = input;
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, input)) return false;
		phone = input;
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, input)) return false;
		secret = input;
	if (firstName.empty() || lastName.empty() || nickname.empty() || phone.empty() || secret.empty())
	{
		std::cout << " _________________________________\n" << std::endl;
		std::cout << " Error: all fields must be filled." << std::endl;
		std::cout << " _________________________________\n" << std::endl;
		return false;
	}
	return true;
}

void Contact::displayFull() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone << std::endl;
	std::cout << "Darkest secret: " << secret << std::endl;
}
