#include <iostream>
#include "iter.hpp"

template <typename T>
void printElement(T &element) {
    std::cout << element << std::endl;
}

template <typename T>
void plusInt(T &element) {
    element += 5;
}


int main(void) {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    std::string stringArray[] = {"hello", "world", "forty", "two"};

    std::cout << "\nTesting:" << std::endl;
    ::iter(intArray, 5, plusInt<int>);

    std::cout << "Testing with int array:" << std::endl;
    ::iter(intArray, 5, printElement<const int>);

    std::cout << "\nTesting with char array:" << std::endl;
    ::iter(charArray, 5, printElement<const char>);

    std::cout << "\nTesting with string array:" << std::endl;
    ::iter(stringArray, 4, printElement<const std::string>);


    return 0;
}