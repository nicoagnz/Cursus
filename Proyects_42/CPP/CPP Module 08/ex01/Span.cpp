#include "Span.hpp"
#include <iostream>
#include <exception>
#include <algorithm>

Span::Span() : _maxSize(0){}

Span::Span(unsigned int n) : _maxSize(n){
	_numbers.reserve(n);
}

Span::Span(const Span& other){
	*this = other;
}

Span::~Span(){}


Span& Span::operator=(const Span& other){
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

void Span::addNumber(int value){
	if (_numbers.size() >= _maxSize)
		throw FullException();

	_numbers.push_back(value);
}


unsigned int Span::shortestSpan() const{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> tmp = _numbers;

	std::sort(tmp.begin(), tmp.end());

	int shortest = tmp[1] - tmp[0];

	for (size_t i = 1; i < tmp.size(); ++i){
		int diff = tmp[i] - tmp[i - 1];

		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

unsigned int Span::longestSpan() const{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (max - min);
}

const char* Span::FullException::what() const throw(){
	return "Span is full";
}

const char* Span::NotEnoughNumbersException::what() const throw(){
	return "Not enough numbers";
}
