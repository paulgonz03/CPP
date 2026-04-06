#include "WrongAnimal.hpp"

// constructors

WrongAnimal::WrongAnimal()
{
    std::cout << "Default WrongAnimal constructor" << std::endl;
    this->_type = "unknown";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// operator

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

// destructor

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor" << std::endl;
}

// member functions

void WrongAnimal::makeSound() const
{
    std::cout << "The unknown WrongAnimal do a generic sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return(this->_type);
}

void WrongAnimal::setType(std::string type)
{
    this->_type = type;
}
