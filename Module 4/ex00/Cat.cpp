#include "Cat.hpp"

// constructors

Cat::Cat() : Animal()
{
    std::cout << "Default cat constructor" << std::endl;
    this->setType("Cat");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy cat constructor called" << std::endl;
}

// operadores

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

// destructors

Cat::~Cat()
{
    std::cout << "cat destructor" << std::endl;
}

// member function 

void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}