#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(const Dog &other);

        Dog &operator=(const Dog &other);

        ~Dog();

        void makeSound() const;
		Brain* getbrain();
};

#endif