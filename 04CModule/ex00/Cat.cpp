#include <iostream>
#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << _type << ": Constructed by default (Cat)" << std::endl;
}

Cat::Cat(Cat const & src)
:Animal()
{
	_type = src._type;
	std::cout << _type << ": Constructed by copy (Cat)" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << _type << ": Destroyed (Cat)" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	_type = rhs._type;
	std::cout << _type << ": Assigned (Cat)" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << _type << ": MEOOOOOOOOOOWWWW" << std::endl;
}
