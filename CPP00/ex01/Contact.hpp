#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string _fistName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact(std::string fisrtName, std::string lastName, std::string nickname, std::string phoneNumer, std::string darkestSecret);

    std::string truncatedFisrtName() const;
    std::string truncatedLastName() const;
    std::string truncatedNickname() const;

    std::string getFisrtName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;

    Contact();
    ~Contact();
};

#endif