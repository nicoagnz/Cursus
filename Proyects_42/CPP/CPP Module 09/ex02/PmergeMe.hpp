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
		int	a;
		int	b;
		int index;
	};

public:
	PmergeMe();
	~PmergeMe();

	void displayBefore() const;
	bool parseInput(int argc, char **argv);
	void sortVector();
	void sortDeque();
	void sortPairs(std::vector<Pair>& pairs, int left, int right);
	void mergePairs(std::vector<Pair>& pairs, int left, int mid, int right);
	std::vector<int> generateJacobsthal(int size);
	std::vector<int> getJacobsthalOrder(int size);
	Pair getPairByIndex(const std::vector<Pair>& pairs, int index);
	int getPosition(const std::vector<int>& mainChain, int value);
	int findInsertPosition(const std::vector<int>& mainChain, int value, int end);
	void displayAfter() const;
};



#endif
