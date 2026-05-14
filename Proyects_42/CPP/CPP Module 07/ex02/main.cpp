#include "Array.hpp"

#include <iostream>
#include "Array.hpp"

int main()
{
	// 1. Constructor with size
	Array<int> a(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i * 10;

	// 2. Verify access and write
	std::cout << "Array a:" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	// 3. Copy constructor (deep copy)
	Array<int> b(a);

	b[0] = 42;

	std::cout << "Array b (modified):" << std::endl;
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	std::cout << "Array a (should remain unchanged):" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	// 4. operator=
	Array<int> c;
	c = a;

	c[1] = 42;

	std::cout << "Array c (assigned and modified):" << std::endl;
	for (unsigned int i = 0; i < c.size(); i++)
		std::cout << c[i] << " ";
	std::cout << std::endl;

	std::cout << "Array a (should remain intact):" << std::endl;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	// 5. Exception test
	try
	{
		std::cout << a[100] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught (out of bounds)" << std::endl;
	}

	return 0;
}


// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL + 1] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }
