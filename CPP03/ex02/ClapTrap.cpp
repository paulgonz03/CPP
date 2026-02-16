#include "ClapTrap.hpp"

ClapTrap::~ClapTrap() {std::cout << "ClapTrap Destructor called" << std::endl;}

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
    std::cout << "ClapTrap copy constructor called" << std::endl;
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap assignment operator called" << std::endl;
    return *this;
}


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
            std::cout << "ClapTrap " << this->name << " be repaired, live points " << this->hitPoints << std::endl;
        }
        else
        {
            std::cout << "ClapTrap " << this->name << " not haved enough energy points" << std::endl;
            return;
        }
    }
}