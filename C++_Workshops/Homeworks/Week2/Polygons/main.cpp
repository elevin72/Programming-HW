/* 
File Name:
Description of program:
Course Name: C++ Workshops
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date: 21/03/2020
Last Modification date:
*/
#include <iostream>
#include <cmath>
#include "polygon.h"
#include "point.h"

using namespace std;

int main()
{ 
    int n;
    cout << "enter number of sides:" << endl;
    cin >> n;

    Point *vertices = new Point[n]; //allocate array of points on stack
    cout << "enter points:" << endl;
    float x, y;
    for(int i = 0; i < n; ++i){ //input info for points for each of the points
        cin >> x >> y;
        vertices[i] = Point(x,y);
    }
    Polygon poly(vertices, n);  //declare polygon
    delete[] vertices;
    if(poly.GetNumVert() == -1){ //ie, is false
        cout << "ERROR" << endl;
        return 0;
    }
    //if polygon was valid then output perimeter
    cout << (int)poly.FindPerimeter() << endl;

    return 0;
}

/*
EXAMPLES

enter number of sides:
3
enter points:
1 1
1 -1
-1 0
5

enter number of sides:
4
enter points:
1 3
-3 6
-4 5
-1 -7
28

enter number of sides:
2
enter points:
1 2 2 1
ERROR

*/


