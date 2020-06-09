#ifndef TRIANGLE_CPP
#define TRIANGLE_CPP
#include "triangle.h"


Triangle::Triangle(int s0, int s1, int s2) {
    _sides = new int[_numSides=3];
    _sides[0] = s0;
    _sides[1] = s1;
    _sides[2] = s2;
}

Triangle::Triangle(const Triangle& t){
    _numSides = 3;
    _sides = new int[3];
    for(int i = 0; i < 3; ++i){
        _sides[i] = t._sides[i];
    }
}



#endif