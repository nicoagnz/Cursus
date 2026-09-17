#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		int number;

		ss >> number;
		if (ss.fail() || !ss.eof() || number <= 0)
			return false;
		_vector.push_back(number);
		_deque.push_back(number);
	}
	return true;
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin();
		it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
