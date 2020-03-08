/* 
File Name:
Description of program:
Course Name: C++ Workshops
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date: 04/03/2020
Last Modification date: 06/03/20
*/
#include <iostream>
#include "circle.h"
using namespace std;

const int NUM_CIRCLES = 3;

int main()
{ 
    //input data from user 3 times, each time input data for a new circle
    cout << "enter the center point and radius of 3 circles" << endl;
    Circle arr[3];
    float centerX, centerY, radius;
    for(int i = 0; i < NUM_CIRCLES; ++i){
        cin >> centerX >> centerY >> radius;
        while(radius <= 0){
            cout << "ERROR" << endl;
            cin >> radius;
        }
        Point center(centerX, centerY);
        arr[i] = Circle(center, radius);
    }

    //print area of circles
    cout << "area";
    char name = 'A';
    for(int i = 0; i < NUM_CIRCLES; ++i, ++name){
        cout << " " << name << ": " << arr[i].CalcArea();
    }

    //print circumference of circles
    cout << endl << "hekef";
    name = 'A';
    for(int i = 0; i < NUM_CIRCLES; ++i, ++name){
        cout << " " << name << ": " << arr[i].CalcCircumference();
    }
    cout << endl;

    Point myDot;
    float x, y;
    int inCircle[NUM_CIRCLES] = {0}; //array of of counters if point is in circle, init to 0

    while (true)
    {
        cin >> x >> y;
        myDot.SetX(x);
        myDot.SetY(y);
        if(myDot.GetX() == 0 && myDot.GetY() == 0){
            break;
        }
        //loop through all the circles, comparing myDot to each circle
        for(int i = 0; i < NUM_CIRCLES; ++i){
            if(arr[i].PointInside(myDot) <= 0){
                ++inCircle[i];
            }
        }
    }
    //print number of dots in each circle
    cout << "num of points in circle" ;
    name = 'A';
    for(int i = 0; i < NUM_CIRCLES; ++i, ++name){
        cout << " " << name << ":" << inCircle[i];
    }
    cout << endl;

    return 0;

}



