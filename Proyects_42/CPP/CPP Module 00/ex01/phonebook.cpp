/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:19:37 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/22 13:09:19 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
}

static std::string format(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::add()
{
	Contact c;
	if (!c.setInfo())
	{
		return;
	}
	contacts[index % 8] = c;
	index++;
	std::cout << "\n---Contact added successfully---\n" << std::endl;
}

void PhoneBook::search()
{
	int	i = 0;
	int idx = 0;
	std::string line;

	while (i < 8 && i < index)
	{
		std::cout << "|" << std::setw(9) << i;
		std::cout << "|" << format(contacts[i].getFirst());
		std::cout << "|" << format(contacts[i].getLast());
		std::cout << "|" << format(contacts[i].getNick());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, line))
	{
		std::cout << "\n D:" << std::endl;
		return;
	}
	if (line.empty())
	{
		std::cout << "No input given." << std::endl;
		return;
	}
	if (line.length() != 1 || !isdigit(line[0]) || line[0] > '7' || line[0] < '0')
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	idx = line[0] - '0';
	if (idx >= index)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	contacts[idx].displayFull();
}
