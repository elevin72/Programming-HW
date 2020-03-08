/* 
File Name: HW5_1.cpp
Description of program: Find Area
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 5 Question 1
Name: Eli Levin 341318228
Creation date: 28-11-19
Last Modification date: 1-11-19
*/
#include <iostream>
using namespace std;

int area(int length, int width);
float area(float radius);

int main()
{ 

    int length, width;
    float radius;
    cout << "enter length and width of the rectangle:" << endl;
    cin >> length >> width;
    cout << area(length, width) << endl;
    cout << "enter radius of the circle:" << endl;
    cin >> radius;
    cout << area(radius) << endl;

    return 0;

}

int area(int length, int width)
{
    while (length < 0 || width < 0)
    {
        cout << "ERROR" << endl;
        cin >> length >> width; 
    }
    int a = length * width;
    return a;
}

float area(float radius)
{
    while (radius <= 0)
    {
        cout << "ERROR" << endl;
        cin >> radius;
    }
    const float pi = 3.14159;
    float a = pi * (radius * radius);
    return a;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW5_1
enter length and width of the rectangle:
34
4
136
enter radius of the circle:
5
78.5397

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW5_1
enter length and width of the rectangle:
4
-1
ERROR
0
3
0
enter radius of the circle:
5
78.5397
*/