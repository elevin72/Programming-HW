/* File Name: HW2_4.cpp
Description of program: accepts 2 ints, performs float algebra on them and prints as a float
Course Name: Intro to Computer Science
Exercise# and Question#: Exercise 2 Question 4
Name: Eli Levin 341318228
Creation date: 11-11-19
Last Modification date: 11-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    int a,b;
    //ask user for 2 integers
    cout << "enter two numbers: " << endl;
    //put each integer in each variable
    cin >> a >> b;

    // c = 5a + 3 / (6b + 2)
    float c = (float)(5*a+3) / (6*b + 2);

    // print c to the page
    cout << "c="<< c << endl;

    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_4
enter two numbers: 
2
0
c=6.5

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_4
enter two numbers: 
5
7
c=0.636364
*/