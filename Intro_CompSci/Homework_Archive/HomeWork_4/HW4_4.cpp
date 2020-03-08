/* 
File Name: HW4_4.cpp
Description of program: Find x after the nth term of a certain expression
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 4 Question 4
Name: Eli Levin 341318228
Creation date: 26-11-19
Last Modification date: 26-11-19
*/
#include <iostream>
using namespace std;

int main() { 
    //First, ask for x and n make sure that n is a positive integer
    int x,n;
    cout << "enter 2 numbers:" << endl;
    cin >> x >> n;
    while(n<1) {
        cout << "ERROR" << endl;
        cin >> n;
    }

    //create some variables to be used throughout the entire loop
    float sum=0;
    int numerator = 1; // numerator and denominator start at 1 so that in the first itiration it's 1/1 * x
    int denominator = 1;  
    int result; 
    for (int i = 0; i < n ; i++) { 
        //POWER FUNCTION - in order to find x to a given exponent
        result = 1; //result must always start at 1 before we start looping
        for (int j = 0; j < denominator; j++){
            result *= x;
        }
        //this is the actual calculation where we calculate each term in the expression
        sum += ((float)numerator/denominator)*result; 
        // now make numerator and denominator correct for the next term.
        numerator *= -1; // every term numerator changes sign
        denominator += 2; // every term the denominator goes up by 2   
    }
    //print our final sum
    cout << sum << endl;
    return 0;
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_4
enter 2 numbers:
0
4
0

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_4
enter 2 numbers:
0
0
ERROR
6
0
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_4
enter 2 numbers:
12
15
2.62592e+08

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_4
enter 2 numbers:
2
10
-21580.2
*/


    

