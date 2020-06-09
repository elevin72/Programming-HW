/* 
Program Name:
Description of program:
Course Name: C++ Workshops
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date: 02/06/2020
Last Modification date:
*/
#include <iostream>
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
using namespace std;

Polygon inputPolygon(int n){
    if(n==3){
        cout << "enter sides for polygon" << endl;
        int a, b, c;
        cin >> a >> b >> c;
        return Triangle(a,b,c);
    }
    if(n==4){
        cout << "enter sides for polygon" << endl;
        int a, b;
        cin >> a >> b;
        return Rectangle(a,b);
    } 
    return Polygon(n);
    

}

int main()
{ 
    int n;
    cout << "enter number of sides for polygon 1" << endl;
    cin >> n;
    Polygon p1 = inputPolygon(n);
    cout << "enter number of sides for polygon 2:" << endl;
    cin >> n;
    if(n != p1.GetNumSides()){
        cout << "not equal" << endl;
        return 0;
    } 
    Polygon p2 = inputPolygon(n);
    cout << (p1.Perimeter() == p2.Perimeter() ? "equal" : "not equal") << endl;
    
    return 0;

}

