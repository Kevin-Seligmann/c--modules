#include <iostream>
#include "ScavTrap.hpp"

// Constructors, destructores, copy, assignment
ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap Has been created with default constructor" << std::endl;
	_hitPoints = ScavDefaultHitPoints;
	_energy = ScavDefaultEnergy;
	_attackDamage = ScavDefaultAttackDamage;
}

ScavTrap::ScavTrap(std::string const & name)
	:ClapTrap(name)
{
	std::cout << "ScavTrap Has been created with a name " << _name << std::endl;
	_hitPoints = ScavDefaultHitPoints;
	_energy = ScavDefaultEnergy;
	_attackDamage = ScavDefaultAttackDamage;
}

ScavTrap::ScavTrap(ScavTrap const & src)
	:ClapTrap(src)
{
	std::cout << "ScavTrap Has been cloned" << std::endl;
	_hitPoints = ScavDefaultHitPoints;
	_energy = ScavDefaultEnergy;
	_attackDamage = ScavDefaultAttackDamage;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Was destroyed" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	ClapTrap::operator=(rhs);
	return *this;
}

// Other members
void ScavTrap::attack(const std::string& target)
{
	if (_energy > 0) 
	{
		_energy --;
		std::cout << "ScavTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
	} 
	else 
	{
		std::cout << "ScavTrap Tried to attack " << target
		<< ", but it's has no energy" << std::endl;
	}
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is in Gatekeeper mode" << std::endl;
}
