#include "phonebook.hpp"


static std::string format(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return std::string(10 - s.length(), ' ') + s;
}

void PhoneBook::add()
{
	Contact c;
	if (!c.setInfo())
	{
		std::cout << "\n---Add cancelled or invalid input---\n" << std::endl;
		return;
	}
	contacts[index % 8] = c;
	index++;
	std::cout << "\n---Contact added successfully---\n" << std::endl;
}

void PhoneBook::search()
{
	int	i = 0;
	int idx = 0;
	std::string line;

	while (i < 8 && i < index)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << format(contacts[i].getFirst());
		std::cout << "|" << format(contacts[i].getLast());
		std::cout << "|" << format(contacts[i].getNick());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, line))
		return;
	if (line.empty())
	{
		std::cout << "No input given." << std::endl;
		return;
	}
	i = 0;
	while (line[i])
	{
		if (!isdigit(line[i]))
		{
			std::cout << "Invalid input." << std::endl;
			return;
		}
		idx = idx * 10 + (line[i] - '0');
		i++;
	}
	if (idx < 0 || idx >= index || idx >= 8)
	{
		std::cout << "Index out of range." << std::endl;
		return;
	}
	contacts[idx].displayFull();
}
