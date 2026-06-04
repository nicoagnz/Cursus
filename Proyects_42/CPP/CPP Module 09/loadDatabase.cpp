#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>


static void trim(std::string& s){
	size_t start = 0;
	while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
		start++;

	size_t end = s.size();
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;

	s = s.substr(start, end - start);
}

static bool isLeap(int year){
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
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

	std::stringstream sy(date.substr(0, 4));
	std::stringstream sm(date.substr(5, 2));
	std::stringstream sd(date.substr(8, 2));

	int year;
	int month;
	int day;

	if (!(sy >> year) || !(sm >> month) || !(sd >> day))
		return false;

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

static bool parseDatabaseLine(const std::string& line, std::string& date, double& rate){
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

void BitcoinExchange::loadDatabase(){
	std::ifstream csv("data.csv");

	if (!csv.is_open())
		throw std::runtime_error("Error: could not open data.csv");

	std::string line;
	std::getline(csv, line);

	int lineNum = 1;

	while (std::getline(csv, line)){
		lineNum++;

		std::string date;
		double rate;

		if (!parseDatabaseLine(line, date, rate)){
			std::stringstream ss;
			ss << "Error: bad database line at " << lineNum << " => " << line;
			throw std::runtime_error(ss.str());
		}

		_db[date] = rate;
	}
}
