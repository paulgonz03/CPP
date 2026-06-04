#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

void RPN::_calculator(std::string operation)
{
    if(_stack.size() < 2)
        throw std::invalid_argument("Not enough tokens");
    int second = _stack.top();
    _stack.pop();
    int first = _stack.top();
    _stack.pop();

    switch (operation[0])
    {
    case '+':
        _stack.push(first + second);
        break;
    case '-':
        _stack.push(first - second);
        break;
    case '*':
        _stack.push(first * second);
        break;
    case '/':
        if(second == 0)
            throw std::runtime_error("Can not divide by 0");
        _stack.push(first / second);
        break;
    }
}

void RPN::parserInput(std::string input)
{
    std::stringstream ss;
    std::string token;

    ss << input;

    while (!_stack.empty())
        _stack.pop();
    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
            _calculator(token);
        else
        {
            if (token.size() != 1 || !isdigit(token[0]))
                throw std::invalid_argument("Invalid token");
            _stack.push(std::atoi(token.c_str()));
        }
    }
    if(_stack.size() != 1)
        throw std::invalid_argument("Invalid token");
    std::cout << _stack.top() << std::endl;
}