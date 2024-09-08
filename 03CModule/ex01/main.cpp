#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main (void){
	ScavTrap b("Barbara");
	ScavTrap c("Carla");

	b.guardGate();

	b.printStats();
	for (int i = 0; i < 51; i++)
	{
		b.attack("Nothing");
	}
	b.printStats();

	c.takeDamage(5);
	c.printStats();

	c.beRepaired(1);
	c.printStats();

	(c = b).printStats();
	c.printStats();

	ScavTrap d(c);
	d.printStats();

	{
		ScavTrap e;
		e.printStats();
	}
	
	return 0;
}
