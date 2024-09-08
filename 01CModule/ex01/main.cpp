#include "Zombie.hpp"
#include <cstdlib>
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

void	writeSeparator(void)
{
	std::cout << std::endl
	<< "----------------------------------------------------"
	<< "----------------------------------------------------"
	<< std::endl << std::endl;
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc != 3)
	{
		std::cerr << "./horde QUANTITY NAME" << std::endl;
		return (0);
	}

	if (atoi(argv[1]) <= 0)
	{
		std::cerr << "Invalid quantity" << std::endl;
		return (0);
	}

	if (std::string(argv[2]).empty())
	{
		std::cerr << "Invalid name" << std::endl;
		return (0);
	}

	writeSeparator();
	std::cout << "Creating horde of zombies and naming them" << std::endl;
	Zombie *zombies = zombieHorde(atoi(argv[1]), argv[2]);

	writeSeparator();
	std::cout << "All zombies will announce themselves" << std::endl;
	for (i = 0; i < atoi(argv[1]); i ++)
	{
		std::cout << "Zombie number " << i + 1 << std::endl;
		zombies[i].announce();
	}

	writeSeparator();
	std::cout << "Calling delete on the zombie array" << std::endl;
	delete[] zombies;
	return (0);
}
