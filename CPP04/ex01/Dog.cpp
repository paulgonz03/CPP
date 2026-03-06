#include "Dog.hpp"

// constructors

Dog::Dog() : Animal()
{
    std::cout << "Default Dog constructor" << std::endl;
    this->_brain = new Brain();
    this->setType("Dog");
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Copy Dog constructor called" << std::endl;
    this->_type = other._type;
    this->_brain = new Brain(*(other._brain));
}

// operadores

Dog &Dog::operator=(const Dog &other)
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

Dog::~Dog()
{
    std::cout << "Dog destructor" << std::endl;
    delete this->_brain;
}

// member function

void Dog::makeSound() const
{
    std::cout << "woof" << std::endl;
}

Brain* Dog::getbrain()
{
	return (this->_brain);
}