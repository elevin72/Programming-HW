/* 
File Name: HW2_7.cpp
Description of program: Find the sum of a 3 digit number
Course Name: Intro to Computer Science
Exercise# and Question#: Exercise 2, Question 7
Name: Eli Levin
Creation date: 11-11-19
Last Modification date: 11-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    int num;
    cout << "enter a three digit number:" << endl;
    cin >> num;


    //this line fetches the digit in the ones place
    int ones = num % 10;
    //this line divides by 10, so it loses the value in the ones place, and then fetches digit in ones place
    int tens = (num / 10) % 10;
    //this line divides by 100, so we lose the values in the ones and tens place, and are only left with the hundreds place
    int hundreds = num / 100;
    
    cout << "the sum is: " << ones + tens + hundreds << endl;

    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_7
enter a 3 digit number:
345
the sum is: 12
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_7
enter a 3 digit number:
000
the sum is: 0
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_7
enter a 3 digit number:
999
the sum is: 27
*/