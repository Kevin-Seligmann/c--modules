#include <iostream>
#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << _type << ": Constructed by default (Cat)" << std::endl;
}

Cat::Cat(Cat const & src)
:AAnimal()
{
	_type = src._type;
	_brain = new Brain();
	*_brain = *src._brain;
	std::cout << _type << ": Constructed by copy (Cat)" << std::endl;
}

Cat::~Cat(void)
{
	delete _brain;
	std::cout << _type << ": Destroyed (Cat)" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		delete _brain;
		_brain = new Brain();
		*_brain = *rhs._brain;
	}
	std::cout << _type << ": Assigned (Cat)" << std::endl;
	return *this;
}

void Cat::makeSound(void) const
{
	delete _brain;
	std::cout << _type << ": MEOOOOOOOOOOWWWW" << std::endl;
}

Brain const *Cat::getBrain(void)
{
	return _brain;
}

void	Cat::setBrain(Brain brain)
{
	delete _brain;
	_brain = new Brain();
	*_brain = brain;
}
