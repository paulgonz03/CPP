#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

class RPN
{
private:
    std::stack<int> _stack;
    void _calculator(std::string operation);
public:
    RPN();
    ~RPN();
    void parserInput(std::string Input);
};


