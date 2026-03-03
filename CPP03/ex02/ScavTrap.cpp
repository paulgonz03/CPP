#include "ScavTrap.hpp"

// constrcutors

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}


ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// destructors

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

// operators 

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
		this->name = other.name;
		this->attackDamage = other.attackDamage;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

// member functions

void ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        this->attackDamage++;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (this->hitPoints <= 0)
    {
        std::cout << "Scavtrap " << this->name << " is dead" << std::endl;
        return;
    }
    else
    {
        std::cout << "Scavtrap " << this->name << " not haved enough energy points" << std::endl;
        return;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " enter in gate keeper mode" << std::endl;
}
