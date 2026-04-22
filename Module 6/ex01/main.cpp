#include "Serializer.hpp"

int main()
{
    Data myData;
    
    myData.id = 42;
    myData.name = "Paula";

    std::cout << "--- ORIGINAL DATA ---" << std::endl;
    std::cout << "Address: " << &myData << std::endl;
    std::cout << "ID:      " << myData.id << std::endl;
    std::cout << "Name:    " << myData.name << std::endl << std::endl;

    uintptr_t serialized = Serializer::serialize(&myData);
    std::cout << "--- SERIALIZED DATA ---" << std::endl;
    std::cout << "uintptr_t value: " << serialized << std::endl << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "--- DESERIALIZED DATA ---" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;

    std::cout << std::endl << "--- COMPARISON ---" << std::endl;
    if (&myData == deserialized)
    {
        std::cout << "SUCCESS! Pointers match." << std::endl;
        std::cout << "Recovered Data - ID: " << deserialized->id << ", Name: " << deserialized->name << std::endl;
    }
    else
    {
        std::cout << "ERROR! Pointers do not match." << std::endl;
    }

    return 0;
}