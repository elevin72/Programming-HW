/* 
File Name: HW4_1.cpp
Description of program: create list of random numbers and test if sorted or not
Course Name: Introduction to Computer Science
Exercise# and Question#: exercise 4 Question 1
Name: Eli Levin 341318228
Creation date: 25-11-19
Last Modification date: 25-11-19
*/
#include <iostream>
#include <ctime>
using namespace std;

int main()
{ 
    srand(time(nullptr));
    int a = rand()%1000 + 1;
    cout << a << " ";

    bool ascending = true;
    int counter = 0;

    while (counter < 2) {
    //create random number b in new variable
    int b = rand()%1000 + 1;
    //if new random number b is smaller than old random number a
    if (b < a)
        ascending = false;
    a = b;
    counter++;
    cout << b << " ";

    }
    //now test if ascending was ever not true during the loop
    if (ascending == false) 
        cout << endl << "not sorted list" << endl;
    else 
        cout << endl << "sorted list" << endl;

    return 0;
}
/*
Test Cases:

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_1 
650 887 133 984 533 365 324 389 830 294 
not sorted list
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_1 
650 887 133 984 533 365 324 389 830 294 
not sorted list
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_1 
650 887 133 984 533 365 324 389 830 294 
not sorted list


I also set counter < 2 in order to test if my sorted list worked
here is output from when the loop only looped 3 times:

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_1 
914 234 41 
not sorted list
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_1 
241 459 484 
sorted list
*/