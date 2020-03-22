#ifndef POINT_CPP
#define POINT_CPP

#include <cmath>
#include "point.h"

float Point::DistanceFrom(Point a){
    //return sqrt( (x1-x2)^2 + (y1-y2)^2 )
    return sqrt(pow(a._x - _x, 2) + pow(a._y - _y, 2));
}

#endif
