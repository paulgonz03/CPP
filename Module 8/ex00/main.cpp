#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    // ---------------- PRUEBA CON VECTOR ----------------
    std::cout << "--- PRUEBA CON std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    // Búsqueda exitosa
    try {
        std::cout << "Buscando 30... ";
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "¡Encontrado! Valor: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    // Búsqueda fallida
    try {
        std::cout << "Buscando 99... ";
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "¡Encontrado! Valor: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    // ---------------- PRUEBA CON LISTA ----------------
    std::cout << "\n--- PRUEBA CON std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(15);
    lst.push_back(25);

    // Búsqueda exitosa
    try {
        std::cout << "Buscando 15... ";
        std::list<int>::iterator itList = easyfind(lst, 15);
        std::cout << "¡Encontrado! Valor: " << *itList << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    // Búsqueda fallida
    try {
        std::cout << "Buscando 100... ";
        std::list<int>::iterator itList2 = easyfind(lst, 100); 
        std::cout << "¡Encontrado! Valor: " << *itList2 << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}