#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(){}
    Point(float x, float y): _x(x), _y(y){}
    void SetX(float x){_x = x;}
    void SetY(float y){_y = y;}
    float GetX(){return _x;}
    float GetY(){return _y;}
    float DistanceFrom(Point a);
private:
    float _x;
    float _y;
};

#endif
