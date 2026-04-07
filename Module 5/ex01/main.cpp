#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        // Test 1: Crear formulario válido
        std::cout << "=== Test 1: Formulario válido ===" << std::endl;
        Form f1("Solicitud1", 30, 50);
        std::cout << f1 << std::endl << std::endl;

        // Test 2: Burócrata con grado suficiente firma formulario
        std::cout << "=== Test 2: Burócrata grado 20 firma (requiere 30) ===" << std::endl;
        Bureaucrat b1("Alice", 20);
        std::cout << b1 << std::endl;
        b1.signForm(f1);
        std::cout << "Después de intentar firmar: " << f1 << std::endl << std::endl;

        // Test 3: Burócrata con grado insuficiente intenta firmar
        std::cout << "=== Test 3: Burócrata grado 40 intenta firmar (requiere 30) ===" << std::endl;
        Bureaucrat b2("Bob", 40);
        Form f2("Solicitud2", 30, 50);
        std::cout << b2 << std::endl;
        b2.signForm(f2);
        std::cout << "Después de intentar firmar: " << f2 << std::endl << std::endl;

        // Test 4: Burócrata con grado exacto
        std::cout << "=== Test 4: Burócrata grado 30 firma (requiere 30) ===" << std::endl;
        Bureaucrat b3("Charlie", 30);
        Form f3("Solicitud3", 30, 50);
        std::cout << b3 << std::endl;
        b3.signForm(f3);
        std::cout << "Después de firmar: " << f3 << std::endl << std::endl;

        // Test 5: Crear formulario con grado inválido
        std::cout << "=== Test 5: Formulario con grado 0 (inválido) ===" << std::endl;
        Form f4("Solicitud4", 0, 50);
    }
    catch (Form::GradeTooHighException &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}

