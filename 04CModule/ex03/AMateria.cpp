#include "AMateria.hpp"
#include <iostream>

// Constructors, destructors
AMateria::AMateria(void)
{
	std::cout << "Default constructor 'AMateria'" << std::endl;
}

AMateria::AMateria(std::string const & type)
:_type(type)
{
	std::cout << "Type constructor 'AMateria': " << _type << std::endl;
}

AMateria::AMateria(AMateria const & src)
:_type(src._type)
{
	(void) src;
	std::cout << "Copy constructor 'AMateria': " << _type << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << "Default destructor 'AMateria': " << _type << std::endl;
}

// Assignment
AMateria & AMateria::operator=(AMateria const & rhs)
{
	(void) rhs;
	std::cout << "Assingment 'AMateria' (type unchanged): " << _type << std::endl;
	return *this;
}

// Getters
std::string const & AMateria::getType() const
{
	return _type;
}

// Not specified by subject, could just print anything
void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " has felt the void" << std::endl;
}
