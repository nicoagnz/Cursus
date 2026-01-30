/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 12:01:09 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/01/30 10:32:40 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Harl harl;

	if (argc == 2) {
		harl.complain(std::string(argv[1]));
	} else {
		std::cout << "Usage: ./harl LEVEL" << std::endl;
		std::cout << "LEVELS: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	return 0;
}
