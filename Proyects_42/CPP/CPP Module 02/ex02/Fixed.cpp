#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {}

Fixed::Fixed(const int n)
{
	_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	_rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	_rawBits = other._rawBits;
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_rawBits = other._rawBits;
	return *this;
}

bool Fixed::operator>(const Fixed& other) const { return _rawBits > other._rawBits; }
bool Fixed::operator<(const Fixed& other) const { return _rawBits < other._rawBits; }
bool Fixed::operator>=(const Fixed& other) const { return _rawBits >= other._rawBits; }
bool Fixed::operator<=(const Fixed& other) const { return _rawBits <= other._rawBits; }
bool Fixed::operator==(const Fixed& other) const { return _rawBits == other._rawBits; }
bool Fixed::operator!=(const Fixed& other) const { return _rawBits != other._rawBits; }

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._rawBits = _rawBits + other._rawBits;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._rawBits = _rawBits - other._rawBits;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long tmp = (long)_rawBits * other._rawBits;
	result._rawBits = tmp >> _fractionalBits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	long tmp = ((long)_rawBits << _fractionalBits) / other._rawBits;
	result._rawBits = tmp;
	return result;
}

Fixed& Fixed::operator++()
{
	_rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	_rawBits += 1;
	return tmp;
}

Fixed& Fixed::operator--()
{
	_rawBits -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	_rawBits -= 1;
	return tmp;
}

float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
