#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
    std::cout << "Constructor Robotomy named" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "Copy constructor Robotomy named" << std::endl;
    *this = other;
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const 
{
    this->checkRequirements(b);
    
    if(rand()%2)
        std::cout << b.getName() << " the robotomy failed" << std::endl;
    else
    {
        std::cout << "vrrrrrrrr....." << std::endl;
        std::cout << b.getName() << " has been robotomized successfully" << std::endl;
    }
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Destructor Robotomy named" << std::endl;
}
