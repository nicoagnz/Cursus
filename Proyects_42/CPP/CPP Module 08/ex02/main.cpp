#include "MutantStack.hpp"

#include <iostream>
#include <list>

using std::cout;
using std::endl;

void subjectTest()
{
	cout << "===== SUBJECT TEST =====" << endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	cout << "Top: " << mstack.top() << endl;

	mstack.pop();

	cout << "Size after pop: " << mstack.size() << endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	cout << "Forward iteration:" << endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite){
		cout << *it << endl;
		++it;
	}

	std::stack<int> s(mstack);

	cout << endl;
}

void copyTest()
{
	cout << "===== COPY TEST =====" << endl;

	MutantStack<int> original;

	original.push(10);
	original.push(20);
	original.push(30);

	MutantStack<int> copy(original);

	cout << "Original:" << endl;

	for (MutantStack<int>::iterator it = original.begin(); it != original.end(); ++it)
		cout << *it << endl;

	cout << "Copy:" << endl;

	for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
		cout << *it << endl;

	cout << endl;
}

void assignationTest()
{
	cout << "===== ASSIGNATION TEST =====" << endl;

	MutantStack<int> a;
	MutantStack<int> b;

	a.push(1);
	a.push(2);
	a.push(3);

	b.push(42);

	b = a;

	cout << "Assigned stack:" << endl;

	for (MutantStack<int>::iterator it = b.begin(); it != b.end(); ++it)
		cout << *it << endl;

	cout << endl;
}

void iteratorTest()
{
	cout << "===== ITERATOR TEST =====" << endl;

	MutantStack<int> stack;

	for (int i = 0; i < 5; i++)
		stack.push(i * 10);

	MutantStack<int>::iterator it = stack.begin();

	cout << "Begin value: " << *it << endl;

	++it;
	cout << "After ++ : " << *it << endl;

	--it;
	cout << "After -- : " << *it << endl;

	cout << endl;
}

void compareWithList()
{
	cout << "===== COMPARE WITH LIST =====" << endl;

	MutantStack<int> mstack;
	std::list<int> lst;

	for (int i = 1; i <= 5; i++){
		mstack.push(i);
		lst.push_back(i);
	}

	cout << "MutantStack:" << endl;

	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		cout << *it << " ";

	cout << endl;

	cout << "List:" << endl;

	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		cout << *it << " ";

	cout << endl << endl;
}

int main()
{
	subjectTest();

	copyTest();

	assignationTest();

	iteratorTest();

	compareWithList();

	return 0;
}
