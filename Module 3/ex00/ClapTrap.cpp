#include "ClapTrap.hpp"

// constructors

ClapTrap::ClapTrap()
{
    std::cout << "Default constructor called" << std::endl;
    this->name = "unknown";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap Constructor called" << std::endl;
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// destructor

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

// operators

ClapTrap &ClapTrap::operator= ( const ClapTrap &other )
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->attackDamage = other.attackDamage;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
	}
	return (*this);
}

// member functions

void ClapTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        this->attackDamage++;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
        return;
    }
    else
    {
        std::cout << "ClapTrap " << this->name << " not haved enough energy points" << std::endl;
        return;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    for (unsigned int i = 0; i < amount; i++)
    {
        if (this->hitPoints > 0)
        {
            this->hitPoints--;
            std::cout << "ClapTrap " << this->name << " be attacked, live points: " << this->hitPoints << std::endl;
        }
        else
        {
            std::cout << "ClapTrap " << this->name << " is dead" << std::endl;
            return;
        }
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    for (unsigned int i = 0; i < amount; i++)
    {
        if (this->energyPoints > 0)
        {
            this->energyPoints--;
            this->hitPoints++;
            std::cout << "ClapTrap " << this->name << " be repaired, live points: " << this->hitPoints << std::endl;
        }
        else
        {
            std::cout << "ClapTrap " << this->name << " not haved enough energy points" << std::endl;
            return;
        }
    }
}
