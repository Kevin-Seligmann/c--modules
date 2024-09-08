#include "FragTrap.hpp"

int main (void)
{
	FragTrap b("Barbara");
	FragTrap c("Carla");

	b.highFivesGuys();

	b.printStats();
	for (int i = 0; i < 101; i++)
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

	FragTrap d(c);
	d.printStats();

	{
		FragTrap e;
		e.printStats();
	}
	
	return 0;
}
