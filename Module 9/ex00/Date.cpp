#include "Date.hpp"

Date::Date(std::string date)
{
    int firstPos = date.find("-");
    int lastPos = date.find_last_of("-");
    std::string tempYear = date.substr(0, firstPos);
    std::string tempMonth = date.substr(firstPos + 1, lastPos - firstPos - 1);
    std::string tempDay = date.substr(lastPos + 1, date.size() - lastPos - 1);
    if (tempYear.size() != 4 || tempMonth.size() != 2 || tempDay.size() != 2)
        throw std::invalid_argument(std::string("bad input => ") + date);
    _year = std::atoi(tempYear.c_str());
    _month = std::atoi(tempMonth.c_str());
    _day = std::atoi(tempDay.c_str());
    if (_month > 12 || _month < 1)
        throw std::invalid_argument(std::string("bad input => ") + date);
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (_day < 1 || _day > months[_month - 1])
        throw std::invalid_argument(std::string("bad input => ") + date);
}

Date::~Date()
{
}

bool Date::operator<(const Date &other) const
{
    if (this->_year < other._year)
        return (true);
    if (this->_year > other._year)
        return (false);
    if (this->_month < other._month)
        return (true);
    if (this->_month > other._month)
        return (false);
    if (this->_day < other._day)
        return (true);
    if (this->_day > other._day)
        return (false);
    return(false);
}