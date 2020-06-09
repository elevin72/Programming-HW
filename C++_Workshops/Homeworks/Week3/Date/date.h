#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date
{
private:
    int _day;
    int _month;
    int _year;
    int ConvertToEpoch() const;
    Date UnconvertFromEpoch(int days) const;
public:
    ///constructors
    Date(int day, int month, int year);
    Date(int day, int month);
    Date(int day);
    Date(){}
    Date(const Date& d);
    void SetDate(int day, int month, int year);

    //operators
    Date operator++();
    Date operator++(int);
    Date operator+=(int d);
    bool operator>(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    
    void Print() const;
    friend std::ostream& operator<<(std::ostream& out, const Date& r);
    friend std::istream& operator>>(std::istream& in, Date& r);
};

#endif