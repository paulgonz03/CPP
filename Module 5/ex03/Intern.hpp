#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:

public:
    Intern();

    Intern(const Intern& other);

    AForm *makeShrubbery(std::string target);
    AForm *makeRobotomy(std::string target);
    AForm *makePresidential(std::string target);
    AForm *makeForm(std::string formName, std::string target);

    Intern &operator=(const Intern& other);

    ~Intern();
};

#endif