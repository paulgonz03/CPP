#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class Weapon;

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;

    public:
        HumanB();
        HumanB(std::string name);
        ~HumanB();

    void attack();
    void setWeapon(Weapon& Weapon);
};

#endif