#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = n << _fractionalBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = other._rawBits;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other._rawBits;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
	return _rawBits >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return os;
}
