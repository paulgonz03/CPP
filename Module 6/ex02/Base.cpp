#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout << "Base destructor called" << std::endl;
}

Base *generate(void)
{
    int nbr = rand() % 3;
    if (nbr == 0)
        return (new A());
    else if (nbr == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    A *testA = dynamic_cast<A *>(p);
    B *testB = dynamic_cast<B *>(p);
    C *testC = dynamic_cast<C *>(p);
    if (testA != NULL)
    {
        std::cout << "A" << std::endl;
        return;
    }
    if (testB != NULL)
    {
        std::cout << "B" << std::endl;
        return;
    }
    if (testC != NULL)
    {
        std::cout << "C" << std::endl;
        return;
    }
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception &e) {}
    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception &e) {}
    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception &e) {}
}
