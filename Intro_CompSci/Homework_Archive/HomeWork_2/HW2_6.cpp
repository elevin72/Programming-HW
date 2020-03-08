/* 
File Name: HW2_6.cpp
Description of program: do algebra with 2 numbers
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 2 Question 6
Name: Eli Levin 341318228
Creation date: 11-11-19
Last Modification date: 11-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    //declare variables
    int a,b;
    //get info from user
    cout << "enter two numbers:" << endl;
    cin >> a;
    cin >> b;

    //add the variables and print
    cout << a << "+" << b << "=" << a+b << endl;
    //subtract the variables and print
    cout << a << "-" << b << "=" << a-b << endl;
    //multiply the variables and print
    cout << a << "*" << b << "=" << a*b << endl;
    //set 'a' as a float and do float algebra
    //divide values and print
    cout << a << "/" << b << "=" << static_cast<float>(a)/b << endl;

    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_6
enter two numbers:
5
6
5+6=11
5-6=-1
5*6=30
5/6=0.833333

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_6
enter two numbers:
78
86
78+86=164
78-86=-8
78*86=6708
78/86=0.906977
*/