#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "Copy ScalarConverter constructor called" << std::endl;
    *this = other;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        return (*this);
    return (*this);
}

static void printConvertion(char c, int n, float f, double d)
{
    if (d < 0 || d > 255)
        std::cout << "char: impossible" << std::endl;
    else if (c >= 32 && c <= 126)
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << f << 'f' << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}

static void charConvert(char input)
{
    int n = static_cast<int>(input);
    float f = static_cast<float>(input);
    double d = static_cast<double>(input);
    printConvertion(input, n, f, d);
}

static void intConvert(int input)
{
    char c = static_cast<char>(input);
    float f = static_cast<float>(input);
    double d = static_cast<double>(input);
    printConvertion(c, input, f, d);
}

static void floatConvert(float input)
{
    char c = static_cast<char>(input);
    int n = static_cast<int>(input);
    double d = static_cast<double>(input);
    printConvertion(c, n, input, d);
}

static void doubleConvert(double input)
{
    char c = static_cast<char>(input);
    int n = static_cast<int>(input);
    float f = static_cast<float>(input);
    printConvertion(c, n, f, input);
}

// static void imposibleConvertion()
// {
//     std::cout << "char: impossible" << std::endl;
//     std::cout << "int: impossible" << std::endl;
//     std::cout << "float: impossible" << std::endl;
//     std::cout << "double: impossible" << std::endl;
// }

static bool pseudoConvertion(std::string input)
{
    int index = 6;
    std::string names[] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};
    for (int i = 0; i < 6; i++)
    {
        if (names[i] == input)
        {
            index = i;
            break;
        }
    }
    if (index == 6)
        return (false);
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    switch (index)
    {
    case 0:
    case 3:
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        break;
    case 1:
    case 4:
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        break;
    case 2:
    case 5:
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        break;
    }
    return (true);
}
static bool quotesManage(std::string &input)
{
    size_t len = input.length();

    if (len >= 2)
    {
        if (input[0] == '\'' && input[len - 1] == '\'')
        {
            input = input.substr(1, len - 2);
            return true;
        }
        if (input[0] == '\"' && input[len - 1] == '\"')
        {
            input = input.substr(1, len - 2);
            return true;
        }
    }
    return false;
}

void ScalarConverter::convert(std::string input)
{
    if (input.empty())
    {
        std::cout << "Wrong input" << std::endl;
        return;
    }
    if (pseudoConvertion(input) == true)
        return;
    if (input.length() == 1 && !isdigit(input[0])) //char
    {
        charConvert(static_cast<char>(input[0]));
        return;
    }
    if (input.find('\'') != std::string::npos || input.find('\"') != std::string::npos)
    {
        if (quotesManage(input) == true)
        {
            if (input.length() == 1)
                charConvert(static_cast<char>(input[0])); //char in quotes
            else
                std::cout << "Wrong input" << std::endl;
        }
        else
            std::cout << "Wrong input" << std::endl;
        return;
    }
    char *endPtr = NULL;
    if (input.find('f') != std::string::npos) // float
    {
        double val = std::strtod(input.c_str(), &endPtr);
        if (*endPtr == 'f' && *(endPtr + 1) == '\0') 
            floatConvert(static_cast<float>(val));
        else
            std::cout << "Wrong input" << std::endl;
    }
    else if (input.find('.') != std::string::npos) // double
    {
        double val = std::strtod(input.c_str(), &endPtr);
        if (*endPtr == '\0') 
            doubleConvert(val);
        else
            std::cout << "Wrong input" << std::endl;
    }
    else // int
    {
        long val = std::strtol(input.c_str(), &endPtr, 10);
        if (*endPtr == '\0') 
        {
            if (val > 2147483647.0 || val < -2147483648.0)
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: impossible" << std::endl;
                std::cout << "double: impossible" << std::endl;
            }
            else
            {
                intConvert(static_cast<int>(val));
            }
        }
        else
            std::cout << "Wrong input" << std::endl;
    }
}
