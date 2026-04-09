#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main()
{
    srand(time(NULL));

    std::cout << MAGENTA << "\n--- CREANDO OBJETOS ---" << RESET << std::endl;
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1); // Grado 1 (jefe máximo, puede hacer todo)
    AForm* form;

    std::cout << CYAN << "\n--- TEST 1: ROBOTOMY REQUEST FORM ---" << RESET << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form; // MUY IMPORTANTE: Liberar la memoria
    }

    std::cout << CYAN << "\n--- TEST 2: SHRUBBERY CREATION FORM ---" << RESET << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Jardin");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << CYAN << "\n--- TEST 3: PRESIDENTIAL PARDON FORM ---" << RESET << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
    if (form)
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << RED << "\n--- TEST 4: FORMULARIO INVENTADO (ERROR ESPERADO) ---" << RESET << std::endl;
    form = someRandomIntern.makeForm("formulario cafetera", "Oficina");
    if (form) // Esto no debería ejecutarse porque form será NULL
    {
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }

    std::cout << MAGENTA << "\n--- DESTRUCTORES ---" << RESET << std::endl;
    return 0;
}