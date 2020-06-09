#ifndef TRIANGLE_H
#define TRIANGle_H
#include "polygon.h"

class Triangle: public Polygon {
    public:
        Triangle(int s0, int s1, int s2);
        Triangle(const Triangle&);
};

#endif