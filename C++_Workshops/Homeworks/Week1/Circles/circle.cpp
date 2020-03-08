#ifndef CIRCLE_CPP
#define CIRCLE_CPP

#include <iostream>
#include <cmath>
#include "circle.h"
using namespace std;

const float PI = 3.14;

//calculate Area of Circle
float Circle::CalcArea(){
    return PI*_radius*_radius;
}

float Circle::CalcCircumference(){
    return PI*_radius*2;
}

//calculate whether point is inside, on, or outside circle
//if point is on circumference, return 0, if inside, return -1, if outside, return 1
int Circle::PointInside(Point dot){
    float distance = DistanceFromCenter(dot);
    if(distance == _radius){
        return 0;
    }
    else if(distance < _radius){
        return -1;
    }
    else {
        return 1;
    }
}

//calculate distance from center of circle
float Circle::DistanceFromCenter(Point dot){
    return sqrt(pow(dot.GetX() -_center.GetX(), 2) + pow(dot.GetY() - _center.GetY(), 2));  
}

#endif
