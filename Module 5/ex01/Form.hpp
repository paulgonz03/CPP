#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _sign;
        const int _execute;

    
    public:
        Form(/* args */);
        beSigned(Bureaucrat bureaucrat);
        ~Form();

        class GradeTooHighException : public std::exception // hereda para poder utilizar el catch 
        {
        public:
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
        public:
            virtual const char *what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);





#endif