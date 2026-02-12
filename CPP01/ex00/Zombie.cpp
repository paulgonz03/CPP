#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie() 
{
    std::cout << this->name << ": died en terrible sufrimiento" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
