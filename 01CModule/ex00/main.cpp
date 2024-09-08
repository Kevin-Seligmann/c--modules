#include <iostream>
#include "Zombie.hpp"

void randomChump(std::string name);

Zombie* newZombie(std::string name);

void	writeSeparator(void)
{
	std::cout << std::endl
	<< "----------------------------------------------------"
	<< "----------------------------------------------------"
	<< std::endl << std::endl;
}
int main(void)
{

	writeSeparator();

	std::cout << "A zombie created on the heap" << std::endl;
	Zombie *heapy = newZombie("Heapy");
	heapy->announce();
	std::cout << "Zombie will be deleted" << std::endl;
	delete heapy;

	writeSeparator();

	std::cout << "A zombie created on the stack" << std::endl;
	randomChump("Stacky");
	std::cout << "End of zombie's lifetime" << std::endl;

	writeSeparator();

	{
		std::cout << "A zombie created on the stack, in a code block, with default constructor" << std::endl;
		Zombie stacky = Zombie();
		stacky.announce();
		std::cout << "Before end of block" << std::endl;
	}
	std::cout << "After end of block" << std::endl;

	writeSeparator();

	return (0);
}
