#include <iostream>
#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i ++)
	{
		_ideas[i] = "Empty...";
	}
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const & src)
{
	for (int i = 0; i < 100; i ++)
	{
		_ideas[i] = src._ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain const & rhs)
{
	for (int i = 0; i < 100; i ++)
	{
		_ideas[i] = rhs._ideas[i];
	}
	std::cout << "Brain assignment called" << std::endl;
	return *this;
}

void Brain::setIdea(std::string const & idea, unsigned int n)
{
	if (n > 100)
	{
		std::cout << "The brain is not large enough" << std::endl;
		return ;
	}
	_ideas[n] = idea;
}

void Brain::setIdeas(std::string const ideas[100])
{
	for (int i = 0; i < 100; i ++)
	{
		_ideas[i] = ideas[i];
	}
}

std::string const & Brain::getIdea(unsigned int n) const
{
	if (n > 100)
	{
		std::cout << "The brain is not large enough, first idea returned" << std::endl;
		return _ideas[0];
	}
	return _ideas[n];
}

std::string const * Brain::getIdeas(void) const
{
	return _ideas;
}
