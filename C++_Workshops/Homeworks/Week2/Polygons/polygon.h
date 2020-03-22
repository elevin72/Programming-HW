#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"

class Polygon
{
public:
    //constructor
    Polygon(Point* vertices, int numVert); //if polygon was illegal then vertices will point to null and numVert will be -1

    //copy constructor
    Polygon(const Polygon& p);

    //destructor
    ~Polygon();

    //calculate perimeter
    float FindPerimeter();

    int GetNumVert(){return _numVert;}

private:
    Point* _vertices;
    int _numVert;
};

#endif