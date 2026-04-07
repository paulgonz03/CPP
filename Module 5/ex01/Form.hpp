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
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form &other);
        
        void beSigned(Bureaucrat bureaucrat);
        bool isSigned() const;
        std::string getName() const;
        int getSign() const;
        int getExecute() const;

        Form &operator=(const Form &other);

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

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif