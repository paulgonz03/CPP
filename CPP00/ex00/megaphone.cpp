#include <string>
#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int i = 1; i < argc; i++) {
        std::string str = argv[i];
        for (int j = 0; j < (int)str.length(); j++)
            std::cout << (char)toupper(str[j]);
    }
    std::cout << std::endl;
    return(0);
}