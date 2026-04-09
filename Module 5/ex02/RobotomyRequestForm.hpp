#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <stdlib.h>

class RobotomyRequestForm : public AForm
{
    private:
    public:
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm &other);

        void execute(Bureaucrat const &b) const;

        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

        ~RobotomyRequestForm();
};

#endif