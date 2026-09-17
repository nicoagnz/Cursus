#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	PmergeMe pmerge;

	if (ac < 2)
	{
		std::cerr << "Error: No input provided." << std::endl;
		return 1;
	}
	if (!pmerge.parseInput(ac, av))
	{
		std::cerr << "Error: Invalid input." << std::endl;
		return 1;
	}
	pmerge.displayBefore();

	return 0;
}
