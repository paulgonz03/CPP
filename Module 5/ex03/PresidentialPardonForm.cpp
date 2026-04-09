#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
    std::cout << "Constructor Presidential named" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "Copy constructor Presidential named" << std::endl;
    *this = other;
}

void PresidentialPardonForm::execute(Bureaucrat const &b) const 
{
    this->checkRequirements(b);

    std::cout << b.getName() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Destructor Presidential named" << std::endl;
}
