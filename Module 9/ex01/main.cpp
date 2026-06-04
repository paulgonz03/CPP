#include "RPN.hpp"

int main(int argc, char **argv)
{   
    if(argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <operations>" << std::endl;
        return(1);
    }
    try
    {
        RPN calculator;
        calculator.parserInput(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return(1);
    }
}