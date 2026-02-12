#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie *paula = new Zombie(name);

    paula->announce();
    return(paula);
}

