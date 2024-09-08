#include "DiamondTrap.hpp"

// Hit points 100
// Energy 50
// Attack 30

int main (void)
{
	DiamondTrap b("Barbara");
	DiamondTrap c("Carla");

	b.highFivesGuys();

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

	DiamondTrap d(c);
	d.printStats();

	{
		DiamondTrap e;
		e.printStats();
	}
	
	return 0;
}
