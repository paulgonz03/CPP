#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
    std::cout << "Bureaucrat constructor named" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Copy bureaucrat constructor called" << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (os);
}

void Bureaucrat::executeForm(AForm const & Aform) const
{
    try
    {
        Aform.execute(*this);
        std::cout << _name << " executed " << Aform.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn't execute " << Aform.getName() << " because: " << e.what() << std::endl;
    }
    
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade - 1 < 1)
        throw(Bureaucrat::GradeTooHighException());
    this->_grade--;
}
void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw(Bureaucrat::GradeTooLowException());
    this->_grade++;
}

void Bureaucrat::signForm(AForm &Aform)
{
    try
    {
        Aform.beSigned(*this);
        std::cout << this->_name << " signed " << Aform.getName() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " << Aform.getName() << " because: " << e.what() << std::endl;
    }
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}
