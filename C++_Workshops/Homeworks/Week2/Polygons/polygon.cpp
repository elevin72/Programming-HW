#ifndef POLYGON_CPP
#define POLYGON_CPP

#include "polygon.h"
using namespace std;

//constructor
Polygon::Polygon(Point* vertices, int numVert)
        :_vertices(vertices),
         _numVert(numVert) {
    if(_numVert <= 2){
        //_vertices = NULL;
        _numVert = -1;
        return;
    }
    _vertices = new Point[numVert];    //make _vertices = to new pointer to array on stack
    for(int i = 0; i < numVert; ++i){  //make each point in new array equal each point in old array
        _vertices[i].SetX(vertices[i].GetX());
        _vertices[i].SetY(vertices[i].GetY());
    }
}

//copy constructor
Polygon::Polygon(const Polygon& p)
        :Polygon(p._vertices, p._numVert){}    //call constructor

//destructor
Polygon::~Polygon(){
    delete[] _vertices;
}

float Polygon::FindPerimeter(){
    float perimeter = 0;
    for(int i = 0; i < _numVert-1; ++i){ //find perimeter of each side up until (not including) the 'last' side
        perimeter += _vertices[i].DistanceFrom(_vertices[i+1]);
    }
    perimeter +=_vertices[_numVert-1].DistanceFrom(_vertices[0]); //find distance from 'last' point to 'first' point
    return perimeter;
}

#endif