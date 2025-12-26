#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "Usage: ./harl LEVEL\n" << std::endl;
		std::cout << "LEVELS: DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 1;
	}

	harl.filter(std::string(argv[1]));
	return 0;
}
