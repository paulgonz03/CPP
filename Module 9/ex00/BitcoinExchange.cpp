#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    _dataBase.clear();
}

BitcoinExchange::~BitcoinExchange()
{
    _dataBase.clear();
}

void BitcoinExchange::_parseDataBase(std::string buffer)
{
    std::size_t pos = buffer.find(",");
    std::string dateStr = buffer.substr(0, pos);
    std::string priceStr = buffer.substr(pos + 1, buffer.size() - pos - 1);
    Date date = Date(dateStr);
    float price = std::atof(priceStr.c_str());
    if (price < 0)
        throw std::invalid_argument("not a positive number");
    if (price > std::numeric_limits<int>::max())
        throw std::invalid_argument("too large a number");
    _dataBase.insert(std::pair<Date, float>(date, price));
}

void BitcoinExchange::extract(std::string fileName)
{
    std::ifstream aInput;
    aInput.open(fileName.c_str(), std::ifstream::in);
    if (!aInput)
        throw std::invalid_argument("Invalid path");
    std::string buffer;
    std::getline(aInput, buffer);
    while (std::getline(aInput, buffer))
    {
        _parseDataBase(buffer);
    }
    aInput.close();
}
void BitcoinExchange::_parseInput(std::string buffer)
{
    std::size_t pos = buffer.find("|");
    std::string dateStr = buffer.substr(0, pos - 1);
    std::string coinsStr = buffer.substr(pos + 2, buffer.size() - pos - 1);
    Date date = Date(dateStr);
    float coins = std::atof(coinsStr.c_str());
    if (coins < 0)
        throw std::invalid_argument("not a positive number");
    if (coins > 1000)
        throw std::invalid_argument("too large a number");
    std::map<Date, float>::iterator mapSearch = _dataBase.find(date);
    if (mapSearch != _dataBase.end()) // que ha encontrado un valor
    {
        coins *= mapSearch->second;
        std::cout << dateStr << " => " << coinsStr << " = " << coins << std::endl;
        return;
    }
    std::map<Date, float>::iterator prev = _dataBase.begin();
    std::map<Date, float>::iterator next = _dataBase.begin();
    next++;
    for (; next != _dataBase.end(); next++)
    {
        if (date < next->first)
        {
            if (date < prev->first)
                throw std::out_of_range("Invalid date");
            coins *= prev->second;
            std::cout << dateStr << " => " << coinsStr << " = " << coins << std::endl;
            return;
        }
        prev++;
    }
    if (next == _dataBase.end())
    {
        coins *= prev->second;
        std::cout << dateStr << " => " << coinsStr << " = " << coins << std::endl;
    }
}

void BitcoinExchange::consultDataBase(std::string fileName)
{
    std::ifstream aInput;
    aInput.open(fileName.c_str(), std::ifstream::in);
    if (!aInput)
        throw std::invalid_argument("Invalid path");
    std::string buffer;
    std::getline(aInput, buffer);
    while (std::getline(aInput, buffer))
    {
        try
        {
            _parseInput(buffer);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << '\n';
        }
    }
}
