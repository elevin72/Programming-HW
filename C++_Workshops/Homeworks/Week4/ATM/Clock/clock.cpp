#ifndef CLOCK_CPP
#define CLOCK_CPP
#include "clock.h"
#include <iostream>
#include <iomanip>
//#include <string>
using namespace std;

//default constructor
Clock::Clock()
{
    _hour = 0;
    _minute = 0;
    _second = 0;
}

//regular constructor
Clock::Clock(int h, int m, int s) : _hour(h), _minute(m), _second(s)
{
    if(_hour < 0){
                throw string("Invalid time - negative number of hours.");
    }
    if(_hour > 23){
           throw string("Wrong time format.");
    }
    if(_minute < 0){
            throw string("Invalid time - negative number of minutes.");
    }
    if(_minute > 59){
        throw string("Invalid time - more than 60 minutes");
    }
    if(_second < 0){
        throw string("Invalid time - negative number of seconds.");
    }
    if(_second > 59){
        throw string("Invalid time - more than 60 seconds");
    }
}

Clock::Clock(int h, int m) : Clock(h,m,0){}

Clock::Clock(int h) : Clock(h,0,0){}

//copy constructor
Clock::Clock(const Clock& c) : Clock(c._hour, c._minute, c._second){}

//setters
void Clock::setHour(int h)
{
    _hour = h;
}

void Clock::setMinute(int m)
{
    _minute = m;
}

void Clock::setSecond(int s)
{
    _second = s;
}

//getters
int Clock::getHour() const 
{ 
    return _hour;
}

int Clock::getMinute() const 
{
    return _minute;
}

int Clock::getSecond() const 
{
    return _second;
}


//operators
Clock Clock::operator+(Clock other) const
{
    int h=0, m=0, s;
    s = (this->_second + other._second);
    if(s > 59){
        s = s%60;
        m = 1;
    }
    m += (this->_minute + other._minute);
    if(m > 59){
        m = m%60;
        h = 1;
    }
    h += (this->_hour + other._hour);
    //if(h > 23){
        h = h%24;
    //}
    return Clock(h,m,s);
}

Clock& Clock::operator+=(int sec)
{
    this->_hour += sec/3600;
    sec = sec%3600;
    this->_minute += sec/60;
    this->_second += sec%60; 
    return *this;
}

//iostream operators
ostream& operator<<(ostream& out, const Clock& c)
{
    out << setw(2) << setfill('0')  << c._hour << ':';
    out << setw(2) << setfill('0')  << c._minute << ':';
    out << setw(2) << setfill('0')  << c._second;
    return out;
}

istream& operator>>(istream& in, Clock& c) 
{
    int h,m,s;
    in >> h >> m >> s;
    c.setHour(h);
    c.setMinute(m);
    c.setSecond(s);
    return in;
}
#endif