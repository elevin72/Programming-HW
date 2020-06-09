#ifndef DATE_CPP
#define DATE_CPP

#include <iostream>
#include "date.h"
using namespace std;

//constructors
Date::Date(int day, int month, int year): _day(day), _month(month), _year(year) {
    if(_day < 1 || _day > 30){
        cout << "Error day" << endl;
        _day = 1;
    }
    if(_month < 1 || _month > 12){
        cout << "Error month" << endl;
        _month = 1;
    }
    if(_year < 1970 || _year > 2099){
        cout << "Error year" << endl;
        _year = 1970;
    }
}

Date::Date(int day, int month): Date(day,month,1970) {}

Date::Date(int day): Date(day,1,1970) {}

Date::Date(const Date& d): Date(d._day, d._month, d._year) {}

void Date::SetDate(int day, int month, int year){
    if(day < 1 || day > 30){
        return;
    }
    if(month < 1 || month > 12){
        return;
    }
    if(year < 1970 || year > 2099){
        return;
    }
    _day = day;
    _month = month;
    _year = year;
}

//prefix-increment
Date Date::operator++(){
    if(_day == 30){
        if(_month == 12){
            if(_year == 2099){
                cout << "ERROR" << endl;
                return *this;
            }
            ++_year;
            _month = 1;
            _day = 1;
            return *this;
        }
        ++_month;
        _day = 1;
        return *this;
    }
    ++_day;
    return *this;
}

//postfix-increment
Date Date::operator++(int){
    Date temp(*this);
    if(_day == 30){
        if(_month == 12){
            if(_year == 2099){
                cout << "ERROR" << endl;
                return temp;
            }
            ++_year;
            _month = 1;
            _day = 1;
            return temp;
        }
        ++_month;
        _day = 1;
        return temp;
    }
    ++_day;
    return temp;
}

Date Date::operator+=(int d){
    return *this = UnconvertFromEpoch(this->ConvertToEpoch() + d);
}

bool Date::operator>(const Date& other) const {
    if(this->ConvertToEpoch() >  other.ConvertToEpoch()){
        return true;
    }
    return false;
}

bool Date::operator<(const Date& other) const {
    if(this->ConvertToEpoch() <  other.ConvertToEpoch()){
        return true;
    }
    return false;
}

bool Date::operator==(const Date& other) const {
    if(this->ConvertToEpoch() ==  other.ConvertToEpoch()){
        return true;
    }
    return false;
}

//This function converts a Date object to an integer representing the number of days since jan 1, 1970, given that all months have 30 days
int Date::ConvertToEpoch() const {
    int numDays = 0;
    numDays += (_year - 1970)*360; //360 is number of days in year in this calendar
    numDays  += (_month - 1)*30; //30 is number of days in each month
    numDays += _day;
    return numDays;
}

//This function accepts an integer 'days' and returns a Date object with 'days' number of days since jan 1, 1970 
Date Date::UnconvertFromEpoch(int days) const {
    Date temp;
    temp._year = (days/360) + 1970;
    days = days % 360;
    temp._month = (days/30) + 1;
    temp._day = days % 30;
    return temp;
}

ostream& operator<<(ostream& out, const Date& r) {
    out << r._day << '/' << r._month << '/' << r._year;
    return out;
}

istream& operator>>(istream& in, Date& r) {
    int d,m,y;
    char slash;
    in >> d >> slash >> m >> slash >> y;
    r.SetDate(d,m,y);
    return in;
}

void Date::Print() const {
    cout << _day << '/' << _month << '/' << _year << endl;
}

#endif