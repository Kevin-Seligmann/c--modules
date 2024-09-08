#include "ClapTrap.hpp"
#include <iostream>

// Constructors, destructors, copy, assignment
ClapTrap::ClapTrap(void)
	:_name("Default ClapTrap")
	,_hitPoints(10)
	,_energy(10)
	,_attackDamage(0)
{
	_printStats();
	std::cout << _name << " Has been created with default constructor" << std::endl;	
}
	
ClapTrap::ClapTrap(std::string const & name)
	:_name(name)
	,_hitPoints(10)
	,_energy(10)
	,_attackDamage(0)
{
	_printStats();
	std::cout << _name << " Has been created with a name" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
	:_name(src._name)
	,_hitPoints(src._hitPoints)
	,_energy(src._energy)
	,_attackDamage(src._attackDamage)
{
	_printStats();
	std::cout << _name << " Has been cloned" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	_printStats();
	std::cout << _name << " was destroyed" << std::endl;
}
	
ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	if (&src != this) 
	{
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energy = src._energy;
		_attackDamage = src._attackDamage;
		_printStats();
		std::cout << _name << " Has been reasigned" << std::endl;
	}
	return *this;
}

// Print stats
void ClapTrap::_printStats(void) const
{
	std::cout << "[Health Points:" << _hitPoints
	<< " Energy:" << _energy 
	<< " Attack Damage:" << _attackDamage  << "] "
	<< "ClapTrap ";
}


// Claptrap actions
void ClapTrap::attack(std::string const & target)
{
	if (_energy > 0) 
	{
		_energy --;
		_printStats();
		std::cout << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	} 
	else 
	{
		_printStats();
		std::cout << _name << " Tried to attack " << target
		<< ", but it's has no energy" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy > 0)
	{
		_hitPoints += amount;
		_energy --;
		_printStats();
		std::cout << _name << " Got repaired by " << amount
		<< " points of health" << std::endl;
	}
	else 
	{
		_printStats();
		std::cout << _name << " Tried to repair itself"
		<< ", but it has no energy" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > _hitPoints)
	{
		_hitPoints = 0;
	}
	else
	{
		_hitPoints -= amount;
	}
	_printStats();
	std::cout << _name << " Took " << amount
	<< " points of damage!, ";
	std::cout << _hitPoints << " Hit points left" << std::endl;
}
