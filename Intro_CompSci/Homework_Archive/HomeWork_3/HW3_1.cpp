/* 
File Name: HW3_1
Description of program: checks if number is a 2 digit positive number, and then checks if the digits are even or odd
Course Name: Introduction to Computer Science
Exercise# and Question#: HW3 Question 1
Name: Eli Levin 341318228
Creation date: 13-11-19
Last Modification date: 13-11-19
*/
#include <iostream>
using namespace std;

int main()
{
    ///ask user for number
    int num;
    cout << "enter a number:" << endl;
    //input number
    cin >> num;
    //if(number is between 10 and 99)
    if (num > 9 && num < 100) {
        //take value of each digit in number, 
        int a = num%10;
        int b = num/10;

        if (a%2==0 && b%2==0) { //they're both even
            cout << "even digits only" << endl;
            cout << a*b << endl;
        } else if (a%2!=0 && b%2!=0) { //they're both odd
            cout << "odd digits only" << endl;
            cout << a+b << endl;
        } else { // it's a mixed number
            cout << "mixed number" << endl;
        }

    } else { //if it didn't meet the original criteria of being between 10 and 99
        cout << "ERROR" << endl;
    }

    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw3_1 
enter a number:
33
odd digits only
6
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw3_1 
enter a number:
68
even digits only
48
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw3_1 
enter a number:
-1
ERROR
*/