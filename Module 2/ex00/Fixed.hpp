#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
private:
    int fixedPoint;
    static const int numberBits;

public:
    Fixed();                            
    Fixed(const Fixed& other);          // constructor de copia
    Fixed& operator=(const Fixed& other); // operador =
    ~Fixed();                        

    int getRawBits(void) const;
    void setRawBits(int const raw);
};


#endif