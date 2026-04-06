#include "Phonebook.hpp"

int Phonebook::count = 0;

Phonebook::Phonebook() {}  // contructor por defecto
Phonebook::~Phonebook() {} // destructor

void Phonebook::addContact()
{
    std::string firstName;
    std::cout << "First name: " << std::endl;
    std::getline(std::cin, firstName);
    if (firstName.empty())
    {
        std::cout << "Empty input" << std::endl;
        return;
    }

    std::string lastName;
    std::cout << "Last name: " << std::endl;
    std::getline(std::cin, lastName);
    if (lastName.empty())
    {
        std::cout << "Empty input" << std::endl;
        return;
    }

    std::string nickname;
    std::cout << "Nickname: " << std::endl;
    std::getline(std::cin, nickname);
    if (nickname.empty())
    {
        std::cout << "Empty input" << std::endl;
        return;
    }

    std::string phoneNumber;
    std::cout << "Phone number: " << std::endl;
    std::getline(std::cin, phoneNumber);
    if (phoneNumber.empty())
    {
        std::cout << "Empty input" << std::endl;
        return;
    }

    std::string darkestSecret;
    std::cout << "Darkest Secret: " << std::endl;
    std::getline(std::cin, darkestSecret);
    if (darkestSecret.empty())
    {
        std::cout << "Empty input" << std::endl;
        return;
    }

    count = count % 8;
    Contact contact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    this->contacts[count] = contact;
    count++;

    std::cout << std::endl
              << "\033[42mContact added...\033[0m" << std::endl
              << std::endl;
}

void Phonebook::searchContact()
{
    if (this->contacts[0].getFisrtName().empty())
    {
        std::cout << "Empty list of contacts" << std::endl;
        return;
    }
    std::cout << "|     index| fisrtname|  lastname|  nickname|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        std::cout << "|         " << i + 1;
        std::cout << "|" << std::right << std::setw(10) << this->contacts[i].truncatedFisrtName();
        std::cout << "|" << std::right << std::setw(10) << this->contacts[i].truncatedLastName();
        std::cout << "|" << std::right << std::setw(10) << this->contacts[i].truncatedNickname();
        std::cout << "|" << std::endl;
    }

    std::cout << std::endl
              << "Write de index number to display de contact" << std::endl
              << std::endl;

    std::string index;
    while (std::getline(std::cin, index))
    {
        int ind = atoi(index.c_str()); // pasar de string a const char[] --> c_str
        if (ind > 0 && ind < 9 && !this->contacts[ind - 1].getFisrtName().empty())
        {
            std::cout << std::endl;
            std::cout << "Fisrt name: " << this->contacts[ind - 1].getFisrtName() << std::endl;
            std::cout << "Last name: " << this->contacts[ind - 1].getLastName() << std::endl;
            std::cout << "Nickname: " << this->contacts[ind - 1].getNickname() << std::endl;
            std::cout << "Phone number: " << this->contacts[ind - 1].getPhoneNumber() << std::endl;
            std::cout << "Darkest secret: " << this->contacts[ind - 1].getDarkestSecret() << std::endl
                      << std::endl;
        }
        else
        {
            std::cout << "\033[41mError : Invalid Contact.\033[0m" << std::endl
                      << std::endl;
            return;
        }
    }
    if (std::cin.eof())
    {
        std::cin.clear();
        std::cout << std::endl;
    }
}
