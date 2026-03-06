#include "WrongCat.hpp"

// constructors

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "Default WrongCat constructor" << std::endl;
    this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "Copy WrongCat constructor called" << std::endl;
}

// operadores

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        this->_type = other._type;
    return (*this);
}

// destructors

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor" << std::endl;
}

// member function 

void WrongCat::makeSound() const
{
    std::cout << "miiiiu" << std::endl;
}