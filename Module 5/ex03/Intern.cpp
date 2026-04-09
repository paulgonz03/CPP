#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor named" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        
    }
    return (*this);
}

AForm *Intern::makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*funcs[3])(std::string) = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential};

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*funcs[i])(target);
        }
    }
    std::cout << "Error: Intern cannot  el ex0create '" << formName << "' because it does not exist." << std::endl;
    return NULL;
}

Intern::~Intern()
{
    std::cout << "Intern destructor named" << std::endl;
}