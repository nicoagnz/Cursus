#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>

class PmergeMe
{
private:
	std::vector<int> _vector;
	std::deque<int>  _deque;

	struct Pair
	{
		int a;
		int b;
		int index;
	};

public:
	PmergeMe();
	~PmergeMe();

	void displayBefore() const;
	void displayAfter() const;
	bool parseInput(int argc, char **argv);
	void sortVector();
	void sortDeque();
	void sortPairs(std::vector<Pair>& pairs, int left, int right);
	void mergePairs(std::vector<Pair>& pairs, int left, int mid, int right);
	std::vector<int> getJacobsthalOrder(int size);
};

#endif
