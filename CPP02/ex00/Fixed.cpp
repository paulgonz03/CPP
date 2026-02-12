#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedPoint = 0; 
    std::cout << "Default constructor called" << std::endl;   
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;   
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;   
    return(this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;   
    this->fixedPoint = raw;
}

Fixed::Fixed(const Fixed& other) // cuando hago Fixed b(a);
{
    std::cout << "Copy constructor called" << std::endl;   
    this->fixedPoint = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) // cuando hago a = b
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return (*this);
}
 
