#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U> 
void iter(T *address, size_t const lenght, void (*f)(U &))
{
    for(size_t i = 0; i < lenght; i++)
        f(address[i]);
}

#endif