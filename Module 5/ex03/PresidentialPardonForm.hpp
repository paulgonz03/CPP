#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    
public:
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(const PresidentialPardonForm &other);

    void execute(Bureaucrat const &b) const;

    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    ~PresidentialPardonForm();
};




#endif