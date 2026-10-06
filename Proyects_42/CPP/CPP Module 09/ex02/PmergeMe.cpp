#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <climits>

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::displayBefore() const
{
	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = _vector.begin();
			it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::displayAfter() const
{
	std::cout << "After:  ";
	for (std::vector<int>::const_iterator it = _vector.begin();
			it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::vector<int> PmergeMe::getJacobsthalOrder(int size)
{
	std::vector<int> order;
	int previous = 1;
	int current = 3;

	while (previous < size)
	{
		int end = current;
		if (end > size)
			end = size;
		for (int i = end; i > previous; --i)
			order.push_back(i);
		int next = current + 2 * previous;
		previous = current;
		current = next;
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
		if (pairs[i].a <= pairs[j].a)
			temp.push_back(pairs[i++]);
		else
			temp.push_back(pairs[j++]);
	}
	while (i <= mid)
		temp.push_back(pairs[i++]);
	while (j <= right)
		temp.push_back(pairs[j++]);
	for (size_t k = 0; k < temp.size(); ++k)
		pairs[left + k] = temp[k];
}

void PmergeMe::sortPairs(std::vector<Pair>& pairs, int left, int right)
{
	if (left >= right)
		return;
	int mid = left + (right - left) / 2;
	sortPairs(pairs, left, mid);
	sortPairs(pairs, mid + 1, right);
	mergePairs(pairs, left, mid, right);
}

static int binaryPosition(const std::vector<int>& chain, int value, int end)
{
	int left = 0;
	int right = end;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (chain[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

static int binaryPosition(const std::deque<int>& chain, int value, int end)
{
	int left = 0;
	int right = end;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (chain[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

void PmergeMe::sortVector()
{
	std::vector<Pair> pairs;
	int odd = -1;
	for (size_t i = 0; i < _vector.size(); i += 2)
	{
		if (i + 1 == _vector.size())
			odd = _vector[i];
		else
		{
			Pair p;
			if (_vector[i] >= _vector[i + 1])
			{
				p.a = _vector[i];
				p.b = _vector[i + 1];
			}
			else
			{
				p.a = _vector[i + 1];
				p.b = _vector[i];
			}
			p.index = 0;
			pairs.push_back(p);
		}
	}
	if (!pairs.empty())
		sortPairs(pairs, 0, static_cast<int>(pairs.size()) - 1);
	for (size_t i = 0; i < pairs.size(); ++i)
		pairs[i].index = static_cast<int>(i) + 1;

	std::vector<int> chain;
	if (!pairs.empty())
		chain.push_back(pairs[0].b);
	for (size_t i = 0; i < pairs.size(); ++i)
		chain.push_back(pairs[i].a);

	int pendingCount = static_cast<int>(pairs.size()) - (pairs.empty() ? 0 : 1);
	if (odd != -1)
		++pendingCount;
	std::vector<int> order = getJacobsthalOrder(pendingCount + (pairs.empty() ? 0 : 1));
	for (size_t i = 0; i < order.size(); ++i)
	{
		int index = order[i];
		if (index <= static_cast<int>(pairs.size()))
		{
			const Pair& p = pairs[index - 1];
			int end = 0;
			while (end < static_cast<int>(chain.size()) && chain[end] != p.a)
				++end;
			if (end == static_cast<int>(chain.size()))
				end = static_cast<int>(chain.size()) - 1;
			int pos = binaryPosition(chain, p.b, end);
			chain.insert(chain.begin() + pos, p.b);
		}
		else if (odd != -1)
		{
			int pos = binaryPosition(chain, odd, static_cast<int>(chain.size()) - 1);
			chain.insert(chain.begin() + pos, odd);
		}
	}
	if (pairs.empty() && odd != -1)
		chain.push_back(odd);
	_vector = chain;
}

void PmergeMe::sortDeque()
{
	std::vector<Pair> pairs;
	int odd = -1;
	for (size_t i = 0; i < _deque.size(); i += 2)
	{
		if (i + 1 == _deque.size())
			odd = _deque[i];
		else
		{
			Pair p;
			if (_deque[i] >= _deque[i + 1])
			{
				p.a = _deque[i];
				p.b = _deque[i + 1];
			}
			else
			{
				p.a = _deque[i + 1];
				p.b = _deque[i];
			}
			p.index = 0;
			pairs.push_back(p);
		}
	}
	if (!pairs.empty())
		sortPairs(pairs, 0, static_cast<int>(pairs.size()) - 1);
	for (size_t i = 0; i < pairs.size(); ++i)
		pairs[i].index = static_cast<int>(i) + 1;

	std::deque<int> chain;
	if (!pairs.empty())
		chain.push_back(pairs[0].b);
	for (size_t i = 0; i < pairs.size(); ++i)
		chain.push_back(pairs[i].a);

	int pendingCount = static_cast<int>(pairs.size()) - (pairs.empty() ? 0 : 1);
	if (odd != -1)
		++pendingCount;
	std::vector<int> order = getJacobsthalOrder(pendingCount + (pairs.empty() ? 0 : 1));
	for (size_t i = 0; i < order.size(); ++i)
	{
		int index = order[i];
		if (index <= static_cast<int>(pairs.size()))
		{
			const Pair& p = pairs[index - 1];
			int end = 0;
			while (end < static_cast<int>(chain.size()) && chain[end] != p.a)
				++end;
			if (end == static_cast<int>(chain.size()))
				end = static_cast<int>(chain.size()) - 1;
			int pos = binaryPosition(chain, p.b, end);
			chain.insert(chain.begin() + pos, p.b);
		}
		else if (odd != -1)
		{
			int pos = binaryPosition(chain, odd, static_cast<int>(chain.size()) - 1);
			chain.insert(chain.begin() + pos, odd);
		}
	}
	if (pairs.empty() && odd != -1)
		chain.push_back(odd);
	_deque = chain;
}

bool PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::stringstream ss(argv[i]);
		long long number;
		ss >> number;
		if (ss.fail() || !ss.eof() || number <= 0 || number > INT_MAX)
			return false;
		_vector.push_back(static_cast<int>(number));
		_deque.push_back(static_cast<int>(number));
	}
	return true;
}
