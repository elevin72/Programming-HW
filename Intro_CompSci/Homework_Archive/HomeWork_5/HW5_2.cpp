/* 
File Name:HW5_2
Description of program:Find perfect numbers
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 5 question 2
Name: Eli Levin 341318228
Creation date: 30-11-19
Last Modification date: 30-11-19
*/
#include <iostream>
using namespace std;

bool perfect(int num);
void printPerfect(int num = 500);

int main()
{ 
    int num; // is it a good or bad thing to use int num in different scopes?
    cout << "enter a number:" << endl;
    cin >> num;
    while (num < 0) //if num is less than 0, ask for it again
    {
        cout << "ERROR" << endl;
        cin >> num;
    }

    printPerfect(num);
    cout << endl;
    printPerfect();
    cout << endl;

    return 0;
}

void printPerfect(int num) 
{
    for(int i = 1; i < num; i++)
    {
        if(perfect(i) == true)
        {
            cout << i << " ";
        }
    }
}

bool perfect(int num) // this function has been debugged and works.
{
    if(num % 2 != 0) // if num is odd
    {
        return false;
    }
    
    int sumOfFactors = num / 2; //automatically start at half. we know that its even, so we know dividing by 2 works
    for (int i = (num/2)-1; i > 0 ; i--) // collect divisbles
    {
        int factor = num / i;
        if(factor * i == num)
        {
            sumOfFactors += i;
        } 
    }
    if (sumOfFactors == num) // now test if the sum is equal to the original
    {
        return true;
    }
    else
    {
        return false;
    }   
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW5_2
enter a number:
-8
ERROR
8
6 
6 28 496 
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW5_2
enter a number:
10000
6 28 496 8128 
6 28 496 
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW5_2
enter a number:
3

6 28 496 
*/