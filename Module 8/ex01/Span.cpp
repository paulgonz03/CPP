#include "Span.hpp"

Span::Span(unsigned int max)
{
    this->_max = max;
}

Span::~Span()
{
}

void Span::addNumber(int i)
{
    if (_numbers.size() == _max)
        throw std::out_of_range("Full Span");
    _numbers.push_back(i);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator final)
{
    while (start != final)
    {
        addNumber(*start);
        start++;
    }
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2)
        throw std::length_error("Span too short");
    int shortest = std::numeric_limits<int>::max();
    int temp;
    for (std::vector<int>::iterator fixed = _numbers.begin(); fixed != _numbers.end(); fixed++)
    {
        std::vector<int>::iterator moved = fixed;
        for (moved++; moved != _numbers.end(); moved++)
        {
            temp = *moved - *fixed;
            if (temp < 0)
                temp *= -1;
            if (temp < shortest)
                shortest = temp;
        }
    }
    return (shortest);
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::length_error("Span too short");
    std::vector<int>::iterator max = std::max_element(_numbers.begin(), _numbers.end());
    std::vector<int>::iterator min = std::min_element(_numbers.begin(), _numbers.end());
    return (*max - *min);
}