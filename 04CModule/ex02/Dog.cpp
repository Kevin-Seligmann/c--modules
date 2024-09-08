#include <iostream>
#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << _type << ": Constructed by default (Dog)" << std::endl;
}

Dog::Dog(Dog const & src)
:AAnimal()
{
	_type = src._type;
	_brain = new Brain();
	*_brain = *(src._brain);
	std::cout << _type << ": Constructed by copy (Dog)" << std::endl;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << _type << ": Destroyed (Dog)" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		_type = rhs._type;
		delete _brain;
		_brain = new Brain();
		*_brain = *(rhs._brain);
	}
	std::cout << _type << ": Assigned (Dog)" << std::endl;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << _type << ": Woof woof!" << std::endl;
}

Brain const *Dog::getBrain(void)
{
	return _brain;
}

void	Dog::setBrain(Brain brain)
{
	delete _brain;
	_brain = new Brain();
	*_brain = brain;
}
