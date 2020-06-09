#ifndef POLYGON_CPP
#define POLYGON_CPP
#include <iostream>
#include "polygon.h"
using namespace std;

Polygon::Polygon(){
    _numSides = 0;
    _sides = NULL;
}

Polygon::Polygon(int numSides) : _numSides(numSides) {
    if(numSides < 3){
        *this = Polygon();
        return;
    }
    _sides = new int[numSides];
    if(_numSides > 4){
        cout << "enter sides for polygon:" << endl;
    }
    for(int i = 0; i < numSides; ++i){
        cin >> _sides[i];
    }
}

Polygon::Polygon(const Polygon& p){ 
    _numSides = p._numSides;
    _sides = new int[_numSides];
    for(int i = 0; i < _numSides; ++i){
        _sides[i] = p._sides[i];
    }
}

Polygon::~Polygon(){
    delete[] _sides;
}

int Polygon::GetNumSides() const {
    return _numSides;
}

int* Polygon::GetSides() const {
    return _sides; //this is not ideal
}

int Polygon::Perimeter() const {
    int p = 0;
    for(int i = 0; i < _numSides; ++i){
        p+=_sides[i];
    }
    return p;
}

bool Polygon::operator==(const Polygon& other) const {
    return _numSides == other._numSides && Perimeter() == other.Perimeter();
}






#endif