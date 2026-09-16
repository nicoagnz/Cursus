#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) : numbers(other.numbers) {}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		numbers = other.numbers;
	return *this;
}

RPN::~RPN() {}

const char *RPN::NotEnoughOperands::what() const throw()
{
	return "Not enough operands";
}

const char *RPN::DivisionByZero::what() const throw()
{
	return "Division by zero";
}

const char *RPN::InvalidExpression::what() const throw()
{
	return "Invalid expression";
}

int RPN::calculate(const std::string &input) {
	while (!numbers.empty())
		numbers.pop();

	std::size_t i = 0;
	while (i < input.size())
	{
		if (std::isspace(static_cast<unsigned char>(input[i])))
		{
			i++;
			continue;
		}
		if (std::isdigit(static_cast<unsigned char>(input[i])))
		{
			if (i + 1 < input.size() && std::isdigit(static_cast<unsigned char>(input[i + 1])))
				throw InvalidExpression();
			if (i + 1 < input.size() && !std::isspace(static_cast<unsigned char>(input[i + 1])))
				throw InvalidExpression();
			numbers.push(input[i] - '0');
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if (numbers.size() < 2)
				throw NotEnoughOperands();
			char c = input[i];
			int b = numbers.top();
			numbers.pop();
			int a = numbers.top();
			numbers.pop();
			if (c == '+')
				numbers.push(a + b);
			else if (c == '-')
				numbers.push(a - b);
			else if (c == '*')
				numbers.push(a * b);
			else if (c == '/')
			{
				if (b == 0)
					throw DivisionByZero();
				numbers.push(a / b);
			}
		}
		else
			throw InvalidExpression();
		i++;
	}
	if (numbers.size() != 1)
		throw InvalidExpression();
	return (numbers.top());
}