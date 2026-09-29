#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int>  _deque;

public:
	PmergeMe();
	~PmergeMe();

	void displayBefore() const;
	bool parseInput(int argc, char **argv);
	void sortVector();
	void sortDeque();
	void PmergeMe::sortPairs(std::vector<Pair>& pairs, int left, int right);
	void PmergeMe::mergePairs(std::vector<Pair>& pairs, int left, int mid, int right);
	void displayAfter() const;
};

struct Pair
{
	int	a;
	int	b;
};

#endif
