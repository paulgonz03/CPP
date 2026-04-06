#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;   
    this->fixedPoint = 0; 
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;   
    *this = other;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = nbr << numberBits; //multiplica por 256
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = (int)(roundf(nbr * (1 << numberBits))); // multiplica y redondea
}

Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;   
}

Fixed& Fixed::operator=(const Fixed& other)
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

float Fixed::toFloat(void) const
{
	return (float)(fixedPoint) / (1 << numberBits);
}

int Fixed::toInt(void) const
{
	return (fixedPoint >> numberBits);
}
