#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

void BitcoinExchange::processInput(const std::string& filename){
	std::ifstream input(filename.c_str());
	if (!input.is_open())
		throw std::runtime_error("Error: could not open file");

	std::string line;
	std::getline(input, line);

	while (std::getline(input, line)){
		try
		{
			std::string date;
			std::string valueStr;

			if (!parseLine(line, date, valueStr))
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}

			if (!parseDate(date))
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}

			double value = parseValue(valueStr);
			double rate = getRateForDate(date);

			std::cout << date << " => " << value
					<< " = " << value * rate << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

double BitcoinExchange::getRateForDate(const std::string& date){
	std::map<std::string, double>::iterator it = _db.lower_bound(date);

	if (it != _db.end() && it->first == date)
		return it->second;

	if (it == _db.begin())
		throw std::runtime_error("Error: no earlier date available");

	if (it == _db.end() || it->first > date)
		--it;
	return it->second;
}

// void BitcoinExchange::loadDatabase(){
// 	std::ifstream csv("data.csv");

// 	if (!csv.is_open())
// 		throw std::runtime_error("Error: could not open data.csv");
	
// 	std::string line;

// 	std::getline(csv, line);

// 	while (std::getline(csv, line)){
// 		size_t pos = line.find(',');

// 		if (pos == std::string::npos || line.find(',', pos + 1) != std::string::npos)
// 			throw std::runtime_error("Error: expected format 'date, value'");

// 		std::string date = line.substr(0, pos);
// 		std::string rateStr = line.substr(pos + 1);

// 		std::stringstream ss(rateStr);

// 		double rate;
// 		ss >> rate;

// 		if (ss.fail() || !ss.eof())
// 			throw std::runtime_error("Error: invalid number in database");

// 		_db[date] = rate;
// 	}
// }
