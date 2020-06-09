#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "polygon.h"

class Rectangle: public Polygon {
    public:
        Rectangle(int s0, int s1);
        Rectangle(const Rectangle&);
};

#endif