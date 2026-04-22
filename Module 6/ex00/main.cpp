// ...existing code...
#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        // Prueba individual introducida por consola
        ScalarConverter::convert(argv[1]);
    }
    else if (argc == 1)
    {
        // Batería de pruebas automática si no se pasan argumentos
        std::cout << "Corriendo bateria de pruebas automatica...\n" << std::endl;

        std::string test_cases[] = {
            "0", "42", "-42", "2147483647", "-2147483648" "23456787654321234567876543",  // Enteros
            "c", "a", "*", "'a'", "\"b\"",                  // Caracteres
            "42.0f", "4.2f", "-4.2f",                       // Floats
            "42.0", "4.2", "-4.2",                          // Doubles
            "nan", "nanf", "+inf", "+inff", "-inf", "-inff",// Pseudo-literales
            "invalid", "12a", "42.0.0", "", "''"            // Casos límite e inválidos
        };

        int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

        for (int i = 0; i < num_cases; i++)
        {
            std::cout << "========================================" << std::endl;
            std::cout << "Input:   [" << test_cases[i] << "]" << std::endl;
            std::cout << "----------------------------------------" << std::endl;
            ScalarConverter::convert(test_cases[i]);
            std::cout << std::endl;
        }
    }
    else
    {
        std::cout << "Usage: ./conversion [value]" << std::endl;
    }

    return 0;
}
