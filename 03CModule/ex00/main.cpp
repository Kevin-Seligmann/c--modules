#include "ClapTrap.hpp"

int main (void){
	ClapTrap a("Ariel");
	ClapTrap b("Bernardo");
	ClapTrap c("Carlos");

	a.attack("Nothing");
	a.attack("Nothing");
	a.attack("Nothing");
	a.attack("Nothing");
	a.attack("Nothing");
	a.attack("Nothing");
	a.attack("Nothing");
	a.attack("Nothing");

	a.takeDamage(5);

	a.beRepaired(0);
	a.beRepaired(1);
	a.beRepaired(2);

	a.attack("Nothing");
	a.beRepaired(10);
	
	b.attack("Carlos");
	c.takeDamage(10);

	b.beRepaired(1);
	b = c;
	b.beRepaired(1);

	ClapTrap d(a);
	d.beRepaired(1);
	a.beRepaired(1);
	return 0;
}
