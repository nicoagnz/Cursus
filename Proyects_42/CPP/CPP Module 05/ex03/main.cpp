/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:31:29 by nikotina          #+#    #+#             */
/*   Updated: 2026/04/07 11:02:22 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	std::srand(time(NULL));

	Bureaucrat boss("Boss", 1);
	Intern someRandomIntern;

	AForm* form;

	std::cout << "\n=== ROBOTOMY REQUEST FORM ===" << std::endl;

	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n=== SHRUBBERY CREATION FORM ===" << std::endl;

	form = someRandomIntern.makeForm("shrubbery creation", "home");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n=== PRESIDENTIAL PARDON FORM ===" << std::endl;

	form = someRandomIntern.makeForm("presidential pardon", "John Doe");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	std::cout << "\n=== INVALID FORM ===" << std::endl;

	form = someRandomIntern.makeForm("unknown form", "target");
	if (form)
		delete form;

	return 0;
}