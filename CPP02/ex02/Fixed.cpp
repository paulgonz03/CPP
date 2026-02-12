#include "Fixed.hpp"

// constrcutores

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

Fixed::Fixed(const Fixed &other) // cuando hago Fixed b(a);
{
    *this = other;
}

// destructor

Fixed::~Fixed(){};

// operadores

Fixed &Fixed::operator=(const Fixed &other) // cuando hago a = b
{
    if (this != &other)
        this->fixedPoint = other.getRawBits();
    return (*this);
}

// comparison
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

// arithmetic

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

// increment

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

// decrement

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

// funciones auxiliares

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

// static functions
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

// output operator
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return os;
}
