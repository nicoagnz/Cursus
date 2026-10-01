#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

std::vector<int> PmergeMe::getJacobsthalOrder(int size)
{
	std::vector<int> order;
	std::vector<bool> used(size + 1, false);

	if (size >= 2)
		used[2] = true;

	int previous = 1;
	int current = 3;

	while (previous < size)
	{
		int end = current;

		if (end > size)
			end = size;

		for (int i = end; i > previous; i--)
		{
			if (!used[i])
			{
				order.push_back(i);
				used[i] = true;
			}
		}

		int next = current + 2 * previous;
		previous = current;
		current = next;
	}

	for (int i = 1; i <= size; i++)
	{
		if (!used[i])
			order.push_back(i);
	}

	return order;
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
	std::vector<int> mainChain;

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

			p.index = pairs.size() + 1;

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

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].index == 2)
		{
			mainChain.push_back(pairs[i].b);
			break;
		}
	}

	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].a);

	std::vector<int> order = getJacobsthalOrder(pairs.size());

	 std::cout << "Main chain: ";

	for (size_t i = 0; i < mainChain.size(); i++)
		std::cout << mainChain[i] << " ";

	std::cout << std::endl;

	if (odd != -1)
		std::cout << "Odd: " << odd << std::endl;

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
