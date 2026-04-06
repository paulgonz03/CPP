#include <string>
#include <iostream>

int main()
{
    std::string temp = "HI THIS IS BRAIN";
    std::string* stringPTR = &temp;
    std::string& stringREF = temp;

    //memory address
    std::cout << "memory addres of temp: " << &temp << std::endl;
    std::cout << "memory addres of PTR: " <<stringPTR << std::endl;
    std::cout << "memory addres of REF: " <<&stringREF << std::endl;

    //value
    std::cout << "Value of temp: " << temp << std::endl;
    std::cout << "Value of PTR: " << *stringPTR << std::endl;
    std::cout << "Value of REF: " << stringREF << std::endl;

}