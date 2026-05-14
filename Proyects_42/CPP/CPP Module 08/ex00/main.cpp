#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> v;

		v.push_back(10);
		v.push_back(20);
		v.push_back(30);
		v.push_back(40);

		std::vector<int>::iterator it1 = easyfind(v, 30);

		std::cout << "Found in vector: " << *it1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Value not found in vector" << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	try
	{
		std::list<int> l;

		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);

		std::list<int>::iterator it2 = easyfind(l, 8);

		std::cout << "Found in list: " << *it2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Value not found in list" << std::endl;
	}

	std::cout << "-------------------" << std::endl;

	try
	{
		std::deque<int> d;

		d.push_back(100);
		d.push_back(200);
		d.push_back(300);

		std::deque<int>::iterator it3 = easyfind(d, 200);

		std::cout << "Found in deque: " << *it3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Value not found in deque" << std::endl;
	}

	return 0;
}