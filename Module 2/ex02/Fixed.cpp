#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixedPoint = 0;
}

Fixed::Fixed(const int nbr)
{
    this->fixedPoint = nbr << numberBits;
}

Fixed::Fixed(const float nbr)
{
    this->fixedPoint = (int)(roundf(nbr * (1 << numberBits)));
}

Fixed::Fixed(const Fixed &other)
{
    *this = other;
}

Fixed::~Fixed() {};


Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return (*this);
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.toFloat() == 0)
    {
        std::cout << "Cannot be divided" << std::endl;
        return (*this);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++(void)
{
    this->fixedPoint++;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;

    this->fixedPoint++;
    return (temp);
}

Fixed &Fixed::operator--(void)
{
    this->fixedPoint--;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;

    this->fixedPoint--;
    return (temp);
}

int Fixed::getRawBits(void) const
{
    return (this->fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return(a);
    return(b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return(a);
    return(b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return(a);
    return(b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return(a);
    return(b);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
