#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

int main()
{
	std::cout << "=== BASIC TEST ===" << std::endl;
	try
	{
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;

		// Esto debe lanzar excepción (overflow)
		std::cout << "Adding overflow..." << std::endl;
		sp.addNumber(42);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== NOT ENOUGH NUMBERS TEST ===" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(10);

		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== ADD RANGE VECTOR TEST ===" << std::endl;
	try
	{
		Span sp(10000);

		std::vector<int> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(i);

		sp.addRange(v.begin(), v.end());

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== ADD RANGE LIST TEST (GENERICITY) ===" << std::endl;
	try
	{
		Span sp(10000);

		std::list<int> l;
		for (int i = 0; i < 10000; i++)
			l.push_back(i * 2);

		sp.addRange(l.begin(), l.end());

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== LARGE RANDOM TEST (10k) ===" << std::endl;
	try
	{
		Span sp(10000);

		std::srand(std::time(NULL));

		for (int i = 0; i < 10000; i++)
			sp.addNumber(std::rand());

		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}