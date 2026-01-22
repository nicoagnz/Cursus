/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:19:26 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/22 11:26:57 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

bool Contact::setInfo()
{
	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, phone);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, secret);
	if (!std::cin)
	{
		std::cout << "\n D:" << std::endl;
		return false;
	}
	if (firstName.empty() || lastName.empty() || nickname.empty() || phone.empty() || secret.empty())
	{
		std::cout << "\n ===================================" << std::endl;
		std::cout << "  Error: all fields must be filled." << std::endl;
		std::cout << " ===================================\n" << std::endl;
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

std::string Contact::getFirst() const 
{
	return firstName;
}

std::string Contact::getLast() const
{
	return lastName;
}
std::string Contact::getNick() const
{
	return nickname;
}
