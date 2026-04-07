#include "Form.hpp"

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _sign(signGrade), _execute(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw(Form::GradeTooHighException());
    if (signGrade > 150 || executeGrade > 150)
        throw(Form::GradeTooLowException());
    std::cout << "Form constructor named" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _sign(other._sign), _execute(other._execute)
{
    this->_signed = other._signed;
    std::cout << "Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

std::string Form::getName() const
{
    return (this->_name);
}

bool Form::isSigned() const
{
    return (this->_signed);
}

int Form::getSign() const
{
    return (this->_sign);
}

int Form::getExecute() const
{
    return (this->_execute);
}

void Form::beSigned(Bureaucrat bureaucrat)
{
    if (bureaucrat.getGrade() > this->_sign)
        throw(Form::GradeTooLowException());
    this->_signed = true;

}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
        << ", sign grade: " << form.getSign() << ", execute grade: " << form.getExecute();
    return (os);
}

Form::~Form()
{
    std::cout << "destructor form named" << std::endl;
}