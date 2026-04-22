#ifndef SERIALIZR_HPP
#define SERIALIZR_HPP

#include <string>
#include <iostream>
#include <cctype> 
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        ~Serializer();
        Serializer &operator=(const Serializer &other);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif