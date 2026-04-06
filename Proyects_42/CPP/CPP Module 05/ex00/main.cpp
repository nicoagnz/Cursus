/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikotina <nikotina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:31:29 by nikotina          #+#    #+#             */
/*   Updated: 2026/04/01 12:21:03 by nikotina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Valid constructor ===" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Constructor with grade too high ===" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Constructor with grade too low ===" << std::endl;
	try
	{
		Bureaucrat c("Charlie", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Grade increment ===" << std::endl;
	try
	{
		Bureaucrat d("Diana", 2);
		std::cout << d << std::endl;
		d.incrementGrade();
		std::cout << d << std::endl;
		d.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Grade decrement ===" << std::endl;
	try
	{
		Bureaucrat e("Eve", 149);
		std::cout << e << std::endl;
		e.decrementGrade();
		std::cout << e << std::endl;
		e.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== Copy constructor ===" << std::endl;
	try
	{
		Bureaucrat f("Frank", 10);
		Bureaucrat g(f);
		std::cout << "Original: " << f << std::endl;
		std::cout << "Copy:     " << g << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Assignment operator (partial copy) ===" << std::endl;
	try
	{
		Bureaucrat h("Henry", 5);
		Bureaucrat i("Isaac", 100);

		std::cout << "Before:" << std::endl;
		std::cout << "h: " << h << std::endl;
		std::cout << "i: " << i << std::endl;

		h = i;

		std::cout << "\nAfter h = i:" << std::endl;
		std::cout << "h: " << h << std::endl;
		std::cout << "i: " << i << std::endl;

		std::cout << "\n(Note that h's name does not change)" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
