#include "Bureaucrat.hpp"

int main()
{
    // Test 1: Crear un Bureaucrat válido
    try
    {
        std::cout << "=== Test 1: Bureaucrat válido ===" << std::endl;
        Bureaucrat b("Alice", 50);
        std::cout << b << std::endl;
        
        b.incrementGrade();
        std::cout << "Después de incrementar: " << b << std::endl;
        
        b.decrementGrade();
        std::cout << "Después de decrementar: " << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Grado demasiado alto (< 1)
    try
    {
        std::cout << "\n=== Test 2: Grado demasiado alto ===" << std::endl;
        Bureaucrat b("Bob", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 3: Grado demasiado bajo (> 150)
    try
    {
        std::cout << "\n=== Test 3: Grado demasiado bajo ===" << std::endl;
        Bureaucrat b("Charlie", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 4: Incrementar hasta el límite
    try
    {
        std::cout << "\n=== Test 4: Incrementar hasta límite ===" << std::endl;
        Bureaucrat b("David", 1);
        std::cout << b << std::endl;
        b.incrementGrade();  // Debería lanzar excepción
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 5: Decrementar hasta el límite
    try
    {
        std::cout << "\n=== Test 5: Decrementar hasta límite ===" << std::endl;
        Bureaucrat b("Eve", 150);
        std::cout << b << std::endl;
        b.decrementGrade();  // Debería lanzar excepción
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}

