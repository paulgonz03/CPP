#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
        return (1);

    std::ifstream aInput;
    aInput.open(argv[1], std::ifstream::in); // abrir archivo de entrada, input
    if (!aInput)
        return(std::cout << "error" << std::endl, 1);
    std::ofstream oInput(std::string(argv[1] + std::string(".replace")).c_str()); // arhivo de salida;
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string buffer;

    while(std::getline(aInput, buffer))
    {
        size_t pos = 0;
        while((pos = buffer.find(s1, pos)) != std::string::npos)
        {
            buffer = buffer.substr(0, pos) + s2 + buffer.substr(pos + s1.length());
            pos += s2.length();
        }
        oInput << buffer << std::endl;
    }
    aInput.close();
    oInput.close();
    return(0);
}
