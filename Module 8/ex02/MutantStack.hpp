#ifndef MUSTANTSTACK_HPP
#define MUSTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack &other);
        ~MutantStack();
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif