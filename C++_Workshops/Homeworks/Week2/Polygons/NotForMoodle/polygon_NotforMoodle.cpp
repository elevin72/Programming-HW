#ifndef POLYGON_CPP
#define POLYGON_CPP

#include "polygon.h"


Polygon::Polygon(Point* vertices, int numVert)
        :_vertices(vertices),
         _numVert(numVert) {
    if(_numVert <= 2){
        _vertices = nullptr;
        _numVert = -1;
        return;
    }
    _vertices = new Point[numVert];    //make _vertices = to new pointer to array on stack
    for(int i = 0; i < numVert; ++i){  //make each point in new array equal each point in old array
        _vertices[i].SetX(vertices[i].GetX());
        _vertices[i].SetY(vertices[i].GetY());
    }
}

Polygon::Polygon(const Polygon& p)
        :Polygon(p._vertices, p._numVert){}    //call constructor

Polygon::~Polygon(){
    delete[] _vertices;
}

float Polygon::FindPerimeter(){
    float perimeter = 0;
    for(int i = 0; i < _numVert-1; ++i){ //find perimeter of each side up until (not including) the 'last' side
        perimeter += _vertices[i].DistanceFrom(_vertices[i+1]);
    }
    perimeter +=_vertices[_numVert].DistanceFrom(_vertices[0]); //find distance from 'last' point to 'first' point
    return perimeter;
}

//********THIS IS WHERE DIFFERENCE STARTS********
class LineSeg
{
    public:
        Point _a;
        Point _b;
        float _slope = a.GetY()-b.GetY() / a.GetX() - b.GetX();
        float _yInt = a.GetY() - _slope()*a.GetX();
        Point _XRange = _a.GetX() <= _b.GetX() ? 
                        Point(_a.GetX(), _b.GetX()) :
                        Point(_b.GetX(), _a.GetX());

        bool IsIntersecting(LineSeg otherLine){

            //check if ranges of each lineSeg are overlapping
            if(_XRange.GetY() < otherLine._XRange.GetX()){
                return false;
            }
            //slope is coeffecient of x, yInt is "free term"
            //float difSlopes = this->slope() - otherLine.slope();
            //float difYInts = otherLine.yInt() - this->yInt();
            //float xVal = (this->slope() - otherLine.slope()) / (otherLine.yInt() - this->yInt());
            
            float xVal = _slope - otherLine._slope / (otherLine._yInt - _yInt);
            if( xVal != _a.GetX() && xVal != _b.GetX()){
                return true;
            } 
            


            
        }
};

bool Polygon::IsNonSelfIntersecting(){

}


#endif