#include "Base.hpp"

int main()
{
    srand(time(NULL));

    std::cout << "Generating a random object..." << std::endl;
    Base* randomObj = generate();

    std::cout << "\nTesting identify(Base* p): ";
    identify(randomObj);

    std::cout << "Testing identify(Base& p): ";
    identify(*randomObj);

    std::cout << "\nCleaning up..." << std::endl;
    delete randomObj;

    return 0;
}