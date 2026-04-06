#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap a;
	FragTrap b("Paula");
	FragTrap c(b);
	FragTrap d;

	a.attack("Adrian");
	b.attack("Mateo");
	c.attack("Oscar");
	a.takeDamage(10);
	a.beRepaired(10);
	b.takeDamage(5);
	b.beRepaired(10);
	c.takeDamage(200);
	c.beRepaired(10);
	c.highFivesGuys();
}