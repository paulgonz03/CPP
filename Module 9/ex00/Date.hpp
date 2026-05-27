#pragma once

#include <iostream>
#include <string>

class Date
{
private:
    int _year;
    int _month;
    int _day;
public:
    Date(std::string date);
    ~Date();
    bool operator<(const Date& other) const;
};


