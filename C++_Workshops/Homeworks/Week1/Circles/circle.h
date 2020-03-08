#ifndef CIRCLE_H
#define CIRCLE_H

class Point
{
public:
    Point(){}
    Point(float x, float y): _x(x), _y(y){}
    void SetX(float x){_x = x;}
    void SetY(float y){_y = y;}
    float GetX(){return _x;}
    float GetY(){return _y;}
private:
    float _x;
    float _y;
};

class Circle
{
public:
    Circle(){}
    Circle(Point center, float radius): _center(center), _radius(radius){}
    void SetCenter(Point center){_center = center;}
    void SetRadius(float radius){_radius = radius;}
    Point GetCenter(){return _center;}
    float GetRadius(){return _radius;}
    float CalcArea();
    float CalcCircumference();
    int PointInside(Point);
private:
    Point _center;
    float _radius;
    float DistanceFromCenter(Point);
};



#endif


