/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 10:41:05 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/07 11:28:35 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	struct FormEntry
	{
		std::string name;
		AForm* (*creator)(const std::string&);
	};

	static const FormEntry forms[] = {
		{"presidential pardon", createPresidential},
		{"robotomy request", createRobotomy},
		{"shrubbery creation", createShrubbery}
	};

	const int size = sizeof(forms) / sizeof(forms[0]);

	for (int i = 0; i < size; i++)
	{
		if (formName == forms[i].name)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}

	std::cout << "Error: form \"" << formName << "\" not found" << std::endl;
	return NULL;
}
