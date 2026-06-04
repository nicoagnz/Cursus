#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

static double parseValue(const std::string& valueStr){
	std::stringstream ss(valueStr);
	double value;

	ss >> value;

	if (ss.fail() || !ss.eof())
		throw std::runtime_error("Error: not a valid number");

	if (value < 0)
		throw std::runtime_error("Error: not a positive number");

	if (value > 1000)
		throw std::runtime_error("Error: too large a number");

	return value;
}

// static bool parseLine(const std::string& line, std::string& date, std::string& valueStr){
// 	size_t pos = line.find('|');

// 	if (pos == std::string::npos ||
// 		line.find('|', pos + 1) != std::string::npos)
// 		return false;

// 	date = line.substr(0, pos);
// 	valueStr = line.substr(pos + 1);

// 	trim(date);
// 	trim(valueStr);

// 	return (!date.empty() && !valueStr.empty());
// }

static bool parseInt(const std::string& s, int& out)
{
	std::stringstream ss(s);
	ss >> out;
	if (ss.fail() || !ss.eof())
		return false;
	return true;
}

static bool parseDate(const std::string& date){
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); i++){
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int month = std::atoi(date.substr(5,2).c_str());
	int day = std::atoi(date.substr(8,2).c_str());

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	return true;
}
