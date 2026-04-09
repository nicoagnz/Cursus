/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacuna-g <nacuna-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:15:54 by nacuna-g          #+#    #+#             */
/*   Updated: 2026/04/09 13:05:05 by nacuna-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// PRINTING FUNCTIONS
static void printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible\n";
	else if (!isprint(static_cast<int>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";
}

static void printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value) ||
		value > std::numeric_limits<int>::max() ||								//////////////////
		value < std::numeric_limits<int>::min())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";
}

static void printFloat(double value)
{
	std::cout << "float: ";
	float f = static_cast<float>(value);

	if (std::isnan(f))
		std::cout << "nanf\n";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff\n" : "-inff\n");
	else
	{
		std::cout << f;
		if (std::floor(f) == f)
			std::cout << ".0";					//////////////////
		std::cout << "f\n";
	}
}

static void printDouble(double value)
{
	std::cout << "double: ";

	if (std::isnan(value))
		std::cout << "nan\n";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf\n" : "-inf\n");
	else
	{
		std::cout << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << "\n";
	}
}
// END PRINTING FUNCTIONS

// TYPE DETECTION FUNCTIONS
static bool isChar(const std::string& s)
{
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isPseudo(const std::string& s)
{
	return (s == "nan" || s == "+inf" || s == "-inf" ||
			s == "nanf" || s == "+inff" || s == "-inff");
}

static bool isInt(const std::string& s)
{
	size_t	i = 0;

	if (s.empty())
		return false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return false;
	while (i < s.length())
		if (!isdigit(s[i++]))
			return false;
	return true;
}

static bool isFloat(const std::string& s)
{
	bool	dot = false;
	bool	digit = false;
	size_t	i = 0;

	if (s.length() < 2)
		return false;
	if (s[s.length() - 1] != 'f')
		return false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i >= s.length() - 1)
		return false;
	while (i < s.length() - 1)
	{
		if (s[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (isdigit(s[i]))
			digit = true;
		else
			return false;
		i++;
	}
	return (dot && digit);
}

static bool isDouble(const std::string& s)
{
	bool dot = false;
	bool digit = false;
	size_t i = 0;

	if (s.empty())
		return false;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i >= s.length())
		return false;
	while(i < s.length())
	{
		if (s[i] == '.')
		{
			if (dot)
				return false;
			dot = true;
		}
		else if (isdigit(s[i]))
			digit = true;
		else
			return false;
		i++;
	}
	return (dot && digit);
}

static e_type detectType(const std::string& s)
{
	if (isChar(s))
		return TYPE_CHAR;
	if (isPseudo(s))
		return TYPE_PSEUDO;
	if (isInt(s))
		return TYPE_INT;
	if (isFloat(s))
		return TYPE_FLOAT;
	if (isDouble(s))
		return TYPE_DOUBLE;
	return TYPE_INVALID;
}
// END TYPE DETECTION FUNCTIONS

static double toDouble(const std::string& s, e_type type)
{
	switch (type)
	{
		case TYPE_CHAR:
			return static_cast<double>(s[1]);
		case TYPE_INT:
		case TYPE_FLOAT:
		case TYPE_DOUBLE:
		case TYPE_PSEUDO:
			return std::strtod(s.c_str(), NULL);
		default:
			return 0.0;
	}
}

// THE MAIN CONVERSION FUNCTION
void ScalarConverter::convert(const std::string& literal)
{
	e_type type = detectType(literal);

	if (type == TYPE_INVALID)
	{
		std::cout << "Invalid input\n";
		return;
	}

	double value = toDouble(literal, type);

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
