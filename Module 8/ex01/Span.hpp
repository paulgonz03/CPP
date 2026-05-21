#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include <algorithm>

class Span
{
private:
    unsigned int _max;
    std::vector<int>  _numbers;
public:
    Span(unsigned int max);
    void addNumber(int i);
    void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator final);
    int shortestSpan();
    int longestSpan();
    ~Span();
};




#endif