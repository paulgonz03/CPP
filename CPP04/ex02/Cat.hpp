#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
    private:
        Brain *_brain;
    public:
        Cat();
        Cat(const Cat &other);

        Cat &operator=(const Cat &other);

        ~Cat();

        void makeSound() const;
		Brain* getbrain();
};

#endif