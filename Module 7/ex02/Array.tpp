#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->array = new T[0]();
    this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->array = new T[n]();
    this->_size = n;
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template <typename T>
Array<T>::Array(const Array &other)
{
    this->_size = other._size;
    this->array = new T[this->_size]();
    for (unsigned int i = 0; i < this->_size; i++)
        this->array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] this->array;
        this->_size = other._size;
        this->array = new T[this->_size]();
        for (unsigned int i = 0; i < this->_size; i++)
            this->array[i] = other.array[i];
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int nbr) 
{
    if (nbr >= this->_size)
        throw(std::exception());
    return(this->array[nbr]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return(this->_size);
}

