#include "Form.hpp"

Form::Form(std::string name, std)
{

}

Form::~Form()
{

}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << form.getName() << ", form grade " << form.getGrade() << ".";
    return (os);
}