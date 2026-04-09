#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _sign(signGrade), _execute(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw(AForm::GradeTooHighException());
    if (signGrade > 150 || executeGrade > 150)
        throw(AForm::GradeTooLowException());
    std::cout << "Constructor AForm named" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _sign(other._sign), _execute(other._execute)
{
    this->_signed = other._signed;
    std::cout << "Copy aform constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

std::string AForm::getName() const
{
    return (this->_name);
}

bool AForm::isSigned() const
{
    return (this->_signed);
}

int AForm::getSign() const
{
    return (this->_sign);
}

int AForm::getExecute() const
{
    return (this->_execute);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_sign)
        throw(AForm::GradeTooLowException());
    this->_signed = true;

}

void AForm::checkRequirements(Bureaucrat const &b) const
{
    if (!this->isSigned())
        throw AForm::NotSignedException();
    if (b.getGrade() > this->getExecute())
        throw AForm::GradeTooLowException();
}

const char *AForm::NotSignedException::what() const throw()
{
    return ("Form is not signed");
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
    os << Aform.getName() << ", signed: " << (Aform.isSigned() ? "yes" : "no")
        << ", sign grade: " << Aform.getSign() << ", execute grade: " << Aform.getExecute();
    return (os);
}

AForm::~AForm()
{
    std::cout << "Destructor Aform named" << std::endl;
}