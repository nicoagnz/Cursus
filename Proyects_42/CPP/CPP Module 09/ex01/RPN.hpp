#include <string>
#include <cctype>
#include <stack>

class RPN {
private:
	std::stack<int> numbers;
public:
	RPN();
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN();

	int calculate(const std::string &input);

	class NotEnoughOperands : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class DivisionByZero : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class InvalidExpression : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};