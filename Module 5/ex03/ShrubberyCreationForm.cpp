#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
    std::cout << "Constructor Shrubbery named" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "Copy constructor Shrubbery named" << std::endl;
    *this = other;
}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const
{
    this->checkRequirements(b);
    
    std::string fileName = b.getName() +  std::string("_shrubbery");
    std::ofstream outFile(fileName.c_str());

    if(!outFile.is_open())
    {
        std::cout << "Open file error" << std::endl;
        return ;
    }

    outFile << "               ,@@@@@@@," << std::endl;
    outFile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outFile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outFile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outFile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outFile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outFile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outFile << "       |o|        | |         | |" << std::endl;
    outFile << "       |.|        | |         | |" << std::endl;
    outFile << "jgs \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

    outFile.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Destructor Shrubbery named" << std::endl;
}
