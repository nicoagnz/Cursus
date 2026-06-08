#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

//======================<<<<<<======================>>>>>>======================//

// Utils Function
static void trim(std::string& s)
{
	size_t start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		start++;

	size_t end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;

	s = s.substr(start, end - start);
}

static bool isLeap(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int toInt(const std::string& s)
{
	int res = 0;
	for (size_t i = 0; i < s.size(); i++)
		res = res * 10 + (s[i] - '0');
	return res;
}

//======================<<<<<<======================>>>>>>======================//

// Parse Date Function
static bool parseDate(const std::string& date)
{
	if (date.size() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return false;
	}

	int year	= toInt(date.substr(0, 4));
	int month	= toInt(date.substr(5, 2));
	int day		= toInt(date.substr(8, 2));

	if (month < 1 || month > 12)
		return false;

	static int daysInMonth[12] =
		{31,28,31,30,31,30,31,31,30,31,30,31};

	int maxDay = daysInMonth[month - 1];

	if (month == 2 && isLeap(year))
		maxDay = 29;

	if (day < 1 || day > maxDay)
		return false;

	return true;
}

static bool parseDatabaseLine(const std::string& line, std::string& date, double& rate)
{
	if (line.empty())
		return false;

	size_t pos = line.find(',');

	if (pos == std::string::npos)
		return false;

	if (line.find(',', pos + 1) != std::string::npos)
		return false;

	std::string dateStr = line.substr(0, pos);
	std::string rateStr = line.substr(pos + 1);

	trim(dateStr);
	trim(rateStr);

	if (dateStr.empty() || rateStr.empty())
		return false;

	if (!parseDate(dateStr))
		return false;

	std::stringstream ss(rateStr);
	double value;

	ss >> value;

	if (ss.fail() || !ss.eof())
		return false;

	date = dateStr;
	rate = value;

	return true;
}

//======================<<<<<<======================>>>>>>======================//

// Parser processInput
double BitcoinExchange::getRateForDate(const std::string& date)
{
	if (_db.empty())
		throw std::runtime_error("Error: database is empty");

	std::map<std::string, double>::iterator it = _db.lower_bound(date);

	if (it != _db.end() && it->first == date)
		return it->second;

	if (it == _db.begin())
		throw std::runtime_error("Error: no earlier date available");

	if (it == _db.end() || it->first > date)
		--it;

	return it->second;
}


static double parseValue(const std::string& valueStr)
{
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

static bool parseLine(const std::string& line, std::string& date, std::string& valueStr)
{
	size_t pos = line.find('|');

	if (pos == std::string::npos)
		return false;

	if (line.find('|', pos + 1) != std::string::npos)
		return false;

	date = line.substr(0, pos);
	valueStr = line.substr(pos + 1);

	trim(date);
	trim(valueStr);

	if (date.empty() || valueStr.empty())
		return false;

	return true;
}

//======================<<<<<<======================>>>>>>======================//

// Main functions
void BitcoinExchange::loadDatabase()
{
	std::ifstream csv("data.csv");

	if (!csv.is_open())
		throw std::runtime_error("Error: could not open data.csv");

	std::string line;
	std::getline(csv, line);

	int lineNum = 1;

	while (std::getline(csv, line))
	{
		lineNum++;

		std::string date;
		double rate;

		if (!parseDatabaseLine(line, date, rate))
		{
			std::stringstream ss;
			ss << "Error: bad database line at " << lineNum << " => " << line;
			throw std::runtime_error(ss.str());
		}

		_db[date] = rate;
	}
}

void BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream input(filename.c_str());
	if (!input.is_open())
		throw std::runtime_error("Error: could not open file");

	std::string line;
	std::getline(input, line);

	while (std::getline(input, line))
	{
		std::string date;
		std::string valueStr;

		trim(line);

		if (line.empty())
			continue;

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

		try
		{
			double value = parseValue(valueStr);

			double rate = getRateForDate(date);

			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
