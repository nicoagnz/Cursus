#pragma once

#include <string>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _db;

		double getRateForDate(const std::string& date);

	public:
		BitcoinExchange(){};
		~BitcoinExchange(){};

		void loadDatabase();
		void processInput(const std::string& filename);
};
