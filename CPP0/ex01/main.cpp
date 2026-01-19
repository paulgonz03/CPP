#include "Phonebook.hpp"

int main()
{
    Phonebook iphone;
    std::string input;

    while (1)
    {
        std::cout << "Command list: ADD, SEARCH, EXIT" << std::endl;
        if (!std::getline(std::cin, input))
        {
            if (std::cin.eof())
            {
                std::cout << std::endl;
                break;
            }
            std::cin.clear();
            continue;
        }
        if (input == "ADD")
        {
            iphone.addContact();
        }
        else if (input == "SEARCH")
        {
            iphone.searchContact();
        }
        else if (input == "EXIT")
        {
            return (0);
        }
        else
        {
            std::cout << "Command not found" << std::endl;
        }
    }
}
