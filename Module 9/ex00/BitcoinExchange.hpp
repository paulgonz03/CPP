#pragma once

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <limits>
#include "Date.hpp"

class BitcoinExchange
{
    private:
        std::map<Date, float> _dataBase;
        void _parseDataBase(std::string buffer);
        void _parseInput(std::string buffer);
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        /**
         * @brief Function to extarct the database information
         * 
         * @param file Database filename
         */
        void extract(std::string filename);
        void consultDataBase(std::string fileName);
};


