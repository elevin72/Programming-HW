/* 
File Name: HW2_5.cpp
Description of program:  ask user for 2 numbers, print them, flip the values and print them again.
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 2 Question 5
Name: Eli Levin 341318228
Creation date: 11-11-19
Last Modification date: 11-11-19
*/
#include <iostream>
using namespace std;

int main()
{
    int x,y;
    cout << "enter two numbers:" << endl;
    cin >> x;
    cin >> y;
        
    cout << "x =" << x << ", y =" << y << endl;

    //now swap the values of the variables

    int placeHolder = x;
    x = y;
    y = placeHolder;

    cout << "x =" << x << ", y =" << y << endl; 

    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_5
enter two numbers:
5
7
x =5, y =7
x =7, y =5
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_5
enter two numbers:
1
1
x =1, y =1
x =1, y =1
*/
