#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _sign;
        const int _execute;

    public:
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(const AForm &other);

        virtual void execute(Bureaucrat const &b) const = 0;
        
        void checkRequirements(Bureaucrat const &b) const;
        void beSigned(Bureaucrat& bureaucrat);
        bool isSigned() const;
        std::string getName() const;
        int getSign() const;
        int getExecute() const;

        AForm &operator=(const AForm &other);

        virtual ~AForm();

        class NotSignedException : public std::exception 
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooHighException : public std::exception
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

std::ostream &operator<<(std::ostream &os, const AForm &Aform);

#endif