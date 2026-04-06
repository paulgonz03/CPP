#include "Cat.hpp"

// constructors

Cat::Cat() : Animal()
{
    std::cout << "Default cat constructor" << std::endl;
    this->_brain = new Brain();
    this->setType("Cat");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Copy cat constructor called" << std::endl;
    this->_type = other._type;
    this->_brain = new Brain(*(other._brain));
}

// operadores

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->_type = other._type;
        delete this->_brain;
        this->_brain = new Brain(*(other._brain));
    }
    return (*this);
}

// destructors

Cat::~Cat()
{
    std::cout << "cat destructor" << std::endl;
    delete this->_brain;
}

// member function 

void Cat::makeSound() const
{
    std::cout << "meow" << std::endl;
}

Brain* Cat::getbrain()
{
	return (this->_brain);
}
