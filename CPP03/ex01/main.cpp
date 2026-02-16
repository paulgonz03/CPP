#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a;
	ScavTrap b("paula");
	ScavTrap c(b);
	ScavTrap d;

	a.attack("adian");
	b.attack("mateo");
	c.attack("oscar");
	a.takeDamage(10);
	a.beRepaired(10);
	b.takeDamage(200);
	b.beRepaired(10);
	b.takeDamage(10);
	c.takeDamage(10);
	c.beRepaired(10);
	c.guardGate();
}
