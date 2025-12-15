#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iomanip>

class PhoneBook {
private:
	Contact contacts[8];
	int index;

public:
	PhoneBook() : index(0) {}
	void add();
	void search();
};

#endif
