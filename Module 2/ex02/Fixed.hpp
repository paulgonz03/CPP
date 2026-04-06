#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int fixedPoint;
    static const int numberBits = 8;

public:
    Fixed();
    Fixed(const int nbr);
    Fixed(const float nbr);
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();

    // comparison
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // arithmetic
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // increment
    Fixed operator++(int);
    Fixed &operator++(void);

    // decrement
    Fixed operator--(int);
    Fixed &operator--(void);

    // fuction
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    
    // static functions
    static Fixed &min(Fixed &a, Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif