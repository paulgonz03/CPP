#include "FragTrap.hpp"

// constructors

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}


FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// destructors

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}
// operators

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
    {
		this->name = other.name;
		this->attackDamage = other.attackDamage;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
    }
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

// member functions

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " wants a high-fives" << std::endl;
}
