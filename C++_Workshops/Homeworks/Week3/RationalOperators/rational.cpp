#ifndef RATIONAL_CPP
#define RATIONAL_CPP

#include "rational.h"
#include <iostream>
using namespace std;

Rational::Rational(int num, int denom): _num(num), _denom(denom ? denom : 1){
    if(!denom){
        cout << "ERROR" << endl;
    }
}

//Print rational number
void Rational::Print(){
    Rational temp = *this;
    temp.Simplify();
    if(temp._denom == 1){
        cout << temp._num<< endl;
        return;
    }
    if(temp._num == 0){
        cout << 0 << endl;
        return;
    }
    cout << temp._num << "/" << temp._denom << endl;
}

bool Rational::operator!=(const Rational& r) const {
     return (float)_num /_denom != (float)r._num / r._denom ? true : false;
}

bool Rational::operator<(const Rational& r) const{
    return (float)_num /_denom < (float)r._num / r._denom ? true : false;
}

bool Rational::operator>(const Rational& r) const{
    return (float)_num /_denom > (float)r._num / r._denom ? true : false;
}

bool Rational::operator>=(const Rational& r) const{
    return (float)_num /_denom >= r._num / (float)r._denom ? true : false;
}

Rational Rational::operator-(const Rational& r) const {
    int num = (_num * r._denom) - (r._num * _denom);
    int denom = r._denom * _denom;
    Rational diff(num, denom);
    return diff.Simplify();
}

Rational Rational::operator--(){
    _num = _num - _denom;
    return *this;
}

Rational Rational::operator--(int){
    Rational temp = *this;
    _num = _num - _denom;
    return temp;
}

Rational Rational::operator++(){
    _num = _num + _denom;
    return *this;
}

Rational Rational::operator++(int){
    Rational temp = *this;
    _num = _num + _denom;
    return temp;
}

Rational Rational::operator/(const Rational& r) const {
    Rational temp(_num * r._denom, _denom * r._num);
    return temp.Simplify();
}

ostream& operator<<(ostream& out, const Rational& r){
    Rational temp = r;
    temp.Simplify();
    if(temp._denom == 1){
        out << temp._num;
        return out;
    }
    if(temp._num == 0){
        out << 0;
        return out;
    }
    out << temp._num << "/" << temp._denom;
    return out;
}


// Equal() function
bool Rational::Equal(Rational frac1){
    frac1 = frac1.Simplify();
    Rational frac2 = Simplify();
    return frac1._num == frac2._num && frac1._denom == frac2._denom;
    
}

int Rational::GreatestCommonFactor(int a, int b){
    if (a == 0)
        return b;
    return GreatestCommonFactor(b % a, a);
}

//Reduce the fraction by dividing both top and bottom by greatest common factor
Rational Rational::Simplify(){
    int gcf = GreatestCommonFactor(_num,_denom);
    Rational reducedFrac(_num/gcf, _denom/gcf);
    return reducedFrac;
}
#endif