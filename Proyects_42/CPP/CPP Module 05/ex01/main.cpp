/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:31:29 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/07 12:32:28 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== BASIC BUREAUCRAT TESTS ===" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== INVALID BUREAUCRAT ===" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== INCREMENT / DECREMENT ===" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 2);
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== FORM CREATION ===" << std::endl;
	try
	{
		Form f1("Form-A", 50, 25);
		std::cout << f1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== INVALID FORM ===" << std::endl;
	try
	{
		Form f2("BadForm", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== SIGN SUCCESS ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 10);
		Form contract("Contract", 20, 10);

		std::cout << contract << std::endl;
		boss.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== SIGN FAILURE ===" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 100);
		Form secret("Secret", 50, 10);

		std::cout << secret << std::endl;
		intern.signForm(secret);
		std::cout << secret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== MULTIPLE SIGN ATTEMPTS ===" << std::endl;
	try
	{
		Bureaucrat chief("Chief", 1);
		Form top("TopSecret", 5, 5);

		chief.signForm(top);
		chief.signForm(top);
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
