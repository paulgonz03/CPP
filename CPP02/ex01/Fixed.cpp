#include "Fixed.hpp"


//contructores 

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;   
    this->fixedPoint = 0; 
}

Fixed::Fixed(const Fixed& other) // cuando hago Fixed b(a);
{
    std::cout << "Copy constructor called" << std::endl;   
    *this = other;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = nbr << numberBits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = (int)(roundf(nbr * (1 << numberBits)));
}

//destructor

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;   
}

//operadores

Fixed& Fixed::operator=(const Fixed& other) // cuando hago a = b
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return (os);
}
 
//funciones auxiliares

int Fixed::getRawBits(void) const
{
    return(this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;   
    this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return (float)(fixedPoint) / (1 << numberBits);
}

int Fixed::toInt(void) const
{
	return (fixedPoint >> numberBits);
}
