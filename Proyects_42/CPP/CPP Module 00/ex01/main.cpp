/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:19:35 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/22 11:11:43 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			return 0;
		}
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
		{
			std::cout << "Goodbye!" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "\n ===================================================" << std::endl;
			std::cout << "  Command not recognized. Try ADD, SEARCH, or EXIT." << std::endl;
			std::cout << " ===================================================\n" << std::endl;
		}
	}
}
