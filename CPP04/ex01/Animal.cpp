#include "Animal.hpp"

// constructors

Animal::Animal()
{
    std::cout << "Default animal constructor called" << std::endl;
    this->_type = "unknown";
}

Animal::Animal(const Animal &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// operator

Animal& Animal::operator=(const Animal& other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

// destructor

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

// member functions

void Animal::makeSound() const
{
    std::cout << "The unknown animal do a generic sound" << std::endl;
}

std::string Animal::getType() const
{
    return(this->_type);
}

void Animal::setType(std::string type)
{
    this->_type = type;
}
