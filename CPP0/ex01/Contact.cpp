#include "Contact.hpp"
#include <string>
#include <iostream>

Contact::Contact(std::string fisrtName, std::string lastName, std::string nickname, std::string phoneNumer, std::string darkestSecret)
{
    this->_fistName = fisrtName;
    this->_lastName = lastName;
    this->_nickname = nickname;
    this->_phoneNumber = phoneNumer;
    this->_darkestSecret = darkestSecret;
}

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::truncatedFisrtName() const
{
    std::string firstName = this->_fistName;
    if (firstName.length() > 10)
        firstName = firstName.substr(0, 9) + ".";
    return (firstName);
}

std::string Contact::truncatedLastName() const
{
    std::string lastName = this->_lastName;
    if (lastName.length() > 10)
        lastName = lastName.substr(0, 9) + ".";
    return (lastName);
}

std::string Contact::truncatedNickname() const
{
    std::string nickname = this->_nickname;
    if (nickname.length() > 10)
        nickname = nickname.substr(0, 9) + ".";
    return (nickname);
}

std::string Contact::getFisrtName() const {return (this->_fistName);}
std::string Contact::getLastName() const {return (this->_lastName);}
std::string Contact::getNickname() const{return (this->_nickname);}
std::string Contact::getPhoneNumber() const{return (this->_phoneNumber);}
std::string Contact::getDarkestSecret() const{return (this->_darkestSecret);}
