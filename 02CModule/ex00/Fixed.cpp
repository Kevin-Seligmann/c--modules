#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
	:_rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & other)
	:_rawBits(other._rawBits)
{
	std::cout << "Copy constructor called raw bits: " << _rawBits << std::endl;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{	
	_rawBits = rhs._rawBits;
	std::cout << "Assignment operator called raw bits: " << _rawBits << std::endl;
	return *this;
}
	
int Fixed::getRawBits(void) const{
	std::cout << "getRawBits called" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int RawBits){
	std::cout << "setRawBits called" << std::endl;
	_rawBits = RawBits;
}
