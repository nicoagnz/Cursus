/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:31:29 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/09 11:22:50 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(time(NULL));

	std::cout << "=== BUREAUCRATS ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Manager", 50);
	Bureaucrat low("Intern", 150);

	std::cout << boss << std::endl;
	std::cout << mid << std::endl;
	std::cout << low << std::endl;

	// =========================================================

	std::cout << "\n=== SHRUBBERY FORM ===" << std::endl;
	ShrubberyCreationForm shrub("home");

	std::cout << shrub << std::endl;

	std::cout << "\n-- Trying to execute without signing --" << std::endl;
	boss.executeForm(shrub);

	std::cout << "\n-- Signing with low grade (should fail) --" << std::endl;
	low.signForm(shrub);

	std::cout << "\n-- Signing with valid bureaucrat --" << std::endl;
	mid.signForm(shrub);

	std::cout << shrub << std::endl;

	std::cout << "\n-- Executing with low grade (should fail) --" << std::endl;
	low.executeForm(shrub);

	std::cout << "\n-- Executing with valid bureaucrat --" << std::endl;
	mid.executeForm(shrub);

	// =========================================================

	std::cout << "\n=== ROBOTOMY FORM ===" << std::endl;
	RobotomyRequestForm robot("Bender");

	mid.signForm(robot);

	std::cout << "\n-- Executing multiple times (50% success rate) --" << std::endl;
	for (int i = 0; i < 5; i++)
		boss.executeForm(robot);

	// =========================================================

	std::cout << "\n=== PRESIDENTIAL PARDON FORM ===" << std::endl;
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "\n-- Signing with insufficient grade --" << std::endl;
	mid.signForm(pardon);

	std::cout << "\n-- Correct signing and execution --" << std::endl;
	boss.signForm(pardon);
	boss.executeForm(pardon);

	// =========================================================

	std::cout << "\n=== POLYMORPHISM TEST ===" << std::endl;

	AForm* forms[3];
	forms[0] = new ShrubberyCreationForm("garden");
	forms[1] = new RobotomyRequestForm("Marvin");
	forms[2] = new PresidentialPardonForm("Ford");

	for (int i = 0; i < 3; i++)
	{
		boss.signForm(*forms[i]);
		boss.executeForm(*forms[i]);
		delete forms[i];
	}

	return 0;
}
