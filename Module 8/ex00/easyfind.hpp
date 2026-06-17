#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &a, int nbr)
{
    typename T::iterator i = std::find(a.begin(), a.end(), nbr);
    if(i == a.end())
        throw std::out_of_range("There is not coincidences..");
    return(i);
}


#endif