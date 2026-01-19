#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

class Phonebook
{
private:
    Contact contacts[8];
    static int count;

public:
    Phonebook();
    ~Phonebook();
    void addContact();
    void searchContact();
};

#endif
