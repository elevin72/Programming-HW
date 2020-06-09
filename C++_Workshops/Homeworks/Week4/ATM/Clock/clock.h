#ifndef CLOCK_H
#define CLOCK_H
#include <iostream>

class Clock {
private:
    int _hour;
    int _minute;
    int _second;
public:
    Clock();
    Clock(int h, int m, int s);
    Clock(int h, int m);
    Clock(int h);
    Clock(const Clock&);
    //~Clock();

    //setters and getters
    void setHour(int h);
    void setMinute(int m);
    void setSecond(int s);
    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    //operators
    Clock operator+(Clock) const;
    Clock& operator+=(int sec);
    //Clock& operator=(const Clock&) const;
    friend std::ostream& operator<<(std::ostream& out, const Clock& r);
    friend std::istream& operator>>(std::istream& in, Clock& r);
};

#endif 
