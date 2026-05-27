#include "BitcoinExchange.hpp"
#define DATABASE_PATH "./data.csv"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usege: " << argv[0] << " <input>" << std::endl;
        return(1);
    }

    BitcoinExchange dataBase;
    try
    {
        /* Guardar la base de datos */
        dataBase.extract(DATABASE_PATH); 
    }
    catch (std::exception &e)
    {   
        std::cout << "Error: " << e.what() << std::endl;
        return(1);
    }
    try
    {
        /* Analizar las consultas */
        dataBase.consultDataBase(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return(1);
    }
    
}
