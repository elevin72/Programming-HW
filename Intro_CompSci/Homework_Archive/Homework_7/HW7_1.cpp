/* 
File Name: HW7_1.cpp
Description of program: Check if user entered all numbers between 1 and 15
Course Name: Introduction to Computer Science
Exercise# and Question#: exercise 7 question 1
Name: Eli Levin 341318228
Creation date: 11-12-19
Last Modification date: 14-12-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    // There are 2 ways to achieve a "NOT GOOD".  1) user enters a number outside of range 1 - 15, or  2) user doubles any number between 1 - 15. 
    // We can test for both with an int array, each int a counter for n-1. If user has entered every number between 1-15, then every element will be equal to 1.
    const int N = 15;
    int arr[N] = {0}; // fill array of size 15 with all zeros
    cout << "enter 15 numbers:" << endl;
    int num;
    for(int i = 0; i < N; i++){ // loop 15 times
        cin >> num;
        if(num > 0 && num <=N){ // if number is within range..
            arr[num-1]++; // ...add 1 to the element
        }
    }
    // Now we must check our array after user entered 15 numbers
    for(int i = 0; i < N; i++){
        if(arr[i] != 1){ // check each element if it's  NOT 1. If any element is not 1 that means that number-1 was not entered.
            cout << "NOT GOOD" << endl;
            break;
        } else if (i == N-1) {
            cout << "GOOD" << endl; // if we have checked the final element of the array and we never breaked the loop, then we are "GOOD".
        }
    }
    return 0;
}

/*
Tests
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_1 
1 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
NOT GOOD
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_1 
1 2 3 4 5 6 7 8 9 10 11 12 13 14
16
NOT GOOD
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_1 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 14
NOT GOOD
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_1 
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
GOOD
*/