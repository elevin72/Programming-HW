/* 
File Name: HW3_4
Description of program: Take 3 inputs and decide if it can be a triangle and what kind of triangle it can be
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 3 Question 4
Name: Eli Levin 341318228
Creation date: 18-11-2019
Last Modification date: 18-11-2019
*/
#include <iostream>
using namespace std;

int main()
{ 
    int a, b, c;
    cout << "enter 3 numbers:" << endl;
    cin >> a >> b >> c;

    // test for negative  or zero sides
    if (a<=0 || b<=0 || c<=0) 
    {
        cout << "no negative or zero sides!" << endl;
        return 0;
    }

    if (a+b>c && b+c>a && a+c>b)
    {
        if (a == b && b == c)
        {
            cout << "equilateral triangle" << endl;
        }
        else if (a!=b && b!=c && a!=c)
        {
            cout << "scalene triangle" << endl;
        }
        else
        {
            cout << "isosceles triangle" << endl;
        }
    }
    else 
    {
        cout << "cannot form a triangle" << endl;
    }

    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_4
enter 3 numbers:
4
7
4
isosceles triangle
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_4
enter 3 numbers:
5
5
5
equilateral triangle
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_4
enter 3 numbers:
0
0
0
no negative or zero sides!
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_4
enter 3 numbers:
5
6
7
scalene triangle
*/
