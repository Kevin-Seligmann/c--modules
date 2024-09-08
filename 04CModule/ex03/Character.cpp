#include <iostream>
#include "Character.hpp"

// Constructors, destructors
Character::Character(void)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Default constructor called, character" << std::endl;
}

Character::Character(std::string const & name)
:_name(name)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		_inventory[i] = NULL;
	}
	std::cout << "Constructor called, character " << _name << std::endl;
}

Character::Character(Character const & src)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (src._inventory[i] != NULL)
		{
			_inventory[i] = src._inventory[i]->clone();
		}
		else
		{
			_inventory[i] = NULL;
		}
	}
	std::cout << "Copy constructor called, character " << _name << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
		}
	}
	std::cout << "Default destructor called, character " << _name << std::endl;
}

// Assignment
Character & Character::operator=(Character const & rhs)
{
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (_inventory[i] != NULL)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		if (rhs._inventory[i] != NULL)
		{
			_inventory[i] = rhs._inventory[i]->clone();
		}
	}
	std::cout << "Assignment called, character " << _name << std::endl;
	return *this;
}

// Getter
std::string const & Character::getName() const 
{
	return _name;
}


// Members
void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < _MaxInventory; i ++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Inventory is full, character " << _name << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > _MaxInventory || _inventory[idx] == NULL)
	{
		std::cout << "Can't unequip this" << std::endl;
	}
	else 
	{
		std::cout << "Unequiped " << _inventory[idx]->getType() << std::endl;
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > _MaxInventory || _inventory[idx] == NULL)
	{
		std::cout << "Can't use this" << std::endl;
	}
	else 
	{
		_inventory[idx]->use(target);
	}
}

