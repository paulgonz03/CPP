#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
    
    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        
        void execute(Bureaucrat const &b) const;

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

        ~ShrubberyCreationForm();
};

#endif