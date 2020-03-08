#ifndef RATIONAL_CPP
#define RATIONAL_CPP

#include "rational.h"
#include <iostream>
using namespace std;

//Print rational number
void Rational::Print(){
    cout << _num << "/" << _denom;
}


// Equal() function
bool Rational::Equal(Rational frac1){
    frac1 = frac1.ReduceFrac();
    Rational frac2 = ReduceFrac();
    return frac1._num == frac2._num && frac1._denom == frac2._denom;
    
}

//Reduce the fraction by dividing both top and bottom by greatest common factor
Rational Rational::ReduceFrac(){
    int min_frac = (_num < _denom ? _num : _denom);
    int common_factor = 1;
    for (int i = 2; i <= min_frac; i++){
        if(_num%i == 0 && _denom%i == 0){
            common_factor = i;
        }
    }
    Rational reducedFrac(_num/common_factor, _denom/common_factor);
    return reducedFrac;
}

#endif