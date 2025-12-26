#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
	Harl harl;

	if (argc == 2) {
		harl.complain(std::string(argv[1]));
	} else {
		std::cout << "Usage: ./harl LEVEL\n" << std::endl;
		std::cout << "LEVELS: DEBUG, INFO, WARNING, ERROR" << std::endl;
	}
	return 0;
}
