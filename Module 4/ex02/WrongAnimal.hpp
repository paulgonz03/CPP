#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(std::string name);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
    virtual ~WrongAnimal();
    virtual void makeSound() const;
    std::string getType() const;
    void setType(std::string type);

};

#endif