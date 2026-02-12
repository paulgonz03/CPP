#include "HumanB.hpp"

HumanB::HumanB() {};
HumanB::~HumanB() {};

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::setWeapon(Weapon& Weapon)
{
    this->weapon = &Weapon;
}

void HumanB::attack()
{
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else 
        std::cout << "not weapon" << std::endl;
}