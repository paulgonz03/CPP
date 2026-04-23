#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <exception>
#include <string>

template <typename T>
class Array
{
    private:
        T *array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        T &operator[](unsigned int nbr);
        unsigned int size() const;
        ~Array();
};

#include "Array.tpp"

#endif