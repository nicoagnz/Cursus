#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Error: Invalid number of arguments." << std::endl;
		return 1;
	}

	try {
		RPN rpn;
		std::cout << rpn.calculate(av[1]) << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
