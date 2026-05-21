#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "=============== MY TEST ===============" << std::endl;

    Span test = Span(10000);
    std::vector<int> temp;
    for (int i = 0; i < 10000; i++)
        temp.push_back(i);
    test.addNumber(temp.begin(), temp.end());
    std::cout << test.shortestSpan() << std::endl;
    std::cout << test.longestSpan() << std::endl;

    std::cout << "============== EXCEPTION ==============" << std::endl;
    Span failed = Span(0);
    try
    {
        failed.addNumber(1);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        failed.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
        try
    {
        failed.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}