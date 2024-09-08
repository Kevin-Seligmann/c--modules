#include <iostream>
#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

void Harl::_debug(void)
{
	std::cout <<  "[DEBUG] I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-"
	"ketchup burger. I really do!" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "[INFO] I cannot believe adding extra bacon "
	"costs more money. You didn’t put "
	"enough bacon " "in my burger! If you did, "
	"I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free."
	" I’ve been coming for years whereas you"
	" started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;

	std::string levels[_levelCount] =
	{
		"INFO", "DEBUG", "WARNING", "ERROR"
	};

	t_func functions[_levelCount] =
	{
		&Harl::_info, &Harl::_debug, &Harl::_warning, &Harl::_error
	};

	while (i < _levelCount)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return ;
		}
		i ++;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
