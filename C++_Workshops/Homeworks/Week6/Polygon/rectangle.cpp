#ifndef RECTANGLE_CPP
#define RECTANGLE_CPP
#include "rectangle.h"

Rectangle::Rectangle(int s0, int s1) {
    _sides = new int[_numSides=4];
    _sides[0] = _sides[2] = s0;
    _sides[1] = _sides[3] = s1;

}

Rectangle::Rectangle(const Rectangle& r){
    _numSides = 4;
    _sides = new int[4];
    for(int i = 0; i < 4; ++i){
        _sides[i] = r._sides[i];
    }
}

#endif