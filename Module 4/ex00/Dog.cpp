#include "Dog.hpp"

// constructors

Dog::Dog() : Animal()
{
    std::cout << "Default Dog constructor" << std::endl;
    this->setType("Dog");
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Copy Dog constructor called" << std::endl;
}

// operadores

Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

// destructors

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
}

// member function 

void Dog::makeSound() const
{
    std::cout << "woof" << std::endl;
}