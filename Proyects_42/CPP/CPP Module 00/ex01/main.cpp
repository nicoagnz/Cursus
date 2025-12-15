#include "phonebook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			break;
		}
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
			break;
		else
		{
			std::cout << "_________________________________________________\n" << std::endl;
			std::cout << "Command not recognized. Try ADD, SEARCH, or EXIT." << std::endl;
			std::cout << "_________________________________________________\n" << std::endl;
		}
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}
