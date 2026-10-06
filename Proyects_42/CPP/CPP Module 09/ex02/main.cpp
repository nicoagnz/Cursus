#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

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
	std::clock_t start = std::clock();
	pmerge.sortVector();
	double vectorTime = 1000000.0 * (std::clock() - start) / CLOCKS_PER_SEC;
	pmerge.displayAfter();

	start = std::clock();
	pmerge.sortDeque();
	double dequeTime = 1000000.0 * (std::clock() - start) / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector: " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque:  " << dequeTime << " us" << std::endl;
	return 0;
}
