#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phone;
	std::string secret;

public:
	bool setInfo();
	void displayFull() const;
	std::string getFirst() const { return firstName; }
	std::string getLast() const { return lastName; }
	std::string getNick() const { return nickname; }
};

#endif
