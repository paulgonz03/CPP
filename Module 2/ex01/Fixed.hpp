#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

class Fixed
{
private:
    int fixedPoint;
    static const int numberBits = 8;

public:
    Fixed();
    Fixed(const int nbr);                            
    Fixed(const float nbr);                            
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();                        

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);


#endif