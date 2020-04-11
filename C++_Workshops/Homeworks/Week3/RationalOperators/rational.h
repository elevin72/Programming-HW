#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
public:

    bool operator!=(const Rational& r) const;
    bool operator<(const Rational& r) const;
    bool operator>(const Rational& r) const;
    bool operator>=(const Rational& r) const;
    Rational operator-(const Rational& r) const;
    Rational operator/(const Rational& r) const;
    //pre-decrement
    Rational operator--();
    //post-decrement
    Rational operator--(int);
    //pre-increment
    Rational operator++();
    //post-increment
    Rational operator++(int);

    

    Rational(int num, int denom);
    Rational(){}
    int GetNum(){return _num;}
    int GetDenom(){return _denom;}
    void SetNum(int n){_num = n;}
    void SetDenom(int d){_denom = d;}
    void Print();
    bool Equal(Rational);
    
private:
    int _num;
    int _denom;
    int GreatestCommonFactor(int a, int b);
    Rational Simplify();  
    friend ostream& operator<<(ostream& out, const Rational& r);
};

#endif
