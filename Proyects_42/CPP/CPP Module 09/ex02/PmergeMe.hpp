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

	bool parseInput(int argc, char **argv);
	void displayBefore() const;
};

#endif
