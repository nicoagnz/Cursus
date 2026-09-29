#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::mergePairs(std::vector<Pair>& pairs, int left, int mid, int right)
{
	std::vector<Pair> temp;

	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (pairs[i].a < pairs[j].a)
		{
			temp.push_back(pairs[i]);
			i++;
		}
		else
		{
			temp.push_back(pairs[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		temp.push_back(pairs[i]);
		i++;
	}

	while (j <= right)
	{
		temp.push_back(pairs[j]);
		j++;
	}

	for (size_t k = 0; k < temp.size(); k++)
		pairs[left + k] = temp[k];
}

void PmergeMe::sortPairs(std::vector<Pair>& pairs, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	sortPairs(pairs, left, mid);
	sortPairs(pairs, mid + 1, right);

	mergePairs(pairs, left, mid, right);
}

void PmergeMe::sortDeque()
{
}
void PmergeMe::sortVector()
{
	std::vector<Pair> pairs;
	int odd = -1;
	for (size_t i = 0; i < _vector.size(); i += 2)
	{
		if (i + 1 >= _vector.size())
		{
			odd = _vector[i];
		}
		else
		{
			Pair p;
			if (_vector[i] > _vector[i + 1])
			{
				p.a = _vector[i];
				p.b = _vector[i + 1];
			}
			else
			{
				p.a = _vector[i + 1];
				p.b = _vector[i];
			}
			pairs.push_back(p);
		}
	}
	if (!pairs.empty())
		sortPairs(pairs, 0, pairs.size() - 1);
	
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin(); it != _vector.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
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
