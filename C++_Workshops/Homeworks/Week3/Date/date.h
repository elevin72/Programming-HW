#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

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
    
    void print() const; //NOT DEFINED
    friend ostream& operator<<(ostream& out, const Date& r);
    friend istream& operator>>(istream& in, Date& r);
};

#endif