#pragma once

#include <vector>

class Span{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
	public:

		class FullException : public std::exception
		{
			public :
				const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int value);

		template <typename It>
		void addRange(It begin, It end){
			for (It it = begin, it != end, ++it){
				if (_numbers.size() >= _maxSize)
					throw FullException();
				_numbers.push_back(*it);
			}
		}

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};
