#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype> 
#include <cstdlib>
#include <iomanip>
#include <limits>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &other);
public:
    void static convert(std::string input);
    
};

#endif