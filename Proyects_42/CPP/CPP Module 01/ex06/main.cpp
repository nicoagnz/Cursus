/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:01:18 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/12 12:01:19 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Usage: ./harl LEVEL\n" << std::endl;
		std::cout << "LEVELS: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}

	harl.filter(std::string(argv[1]));
	return 0;
}
