/* 
File Name: HW3_6
Description of program: tell how mnay days in a month according to which month is input
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 3 Question 6
Name: Eli Levin 341318228
Creation date: 18-11-2019
Last Modification date: 18-11-2019
*/
#include <iostream>
using namespace std;

int main()
{ 
    enum MONTH {JAN=1, FEB, MARCH, APRIL, MAY, JUNE, JULY, AUG, SEPT, OCT, NOV, DEC};
    int mon = 0, days;
    cout << "enter a number:" << endl;
    cin >> mon;

    switch (mon)
    {
    case JAN:
        days = 31;
        break;
    case FEB:
        days = 28;
        break;
    case MARCH:
        days = 31;
        break;
    case APRIL:
        days = 30;
        break;
    case MAY:
        days = 31;
        break;
    case JUNE:
        days = 30;
        break;
    case JULY:
        days = 31;
        break;
    case AUG:
        days = 31;
        break;
    case SEPT:
        days = 30;
        break;
    case OCT:
        days = 31;
        break;
    case NOV:
        days = 30;
        break;
    case DEC:
        days = 31;
        break;
    }

    cout << days << " days in the month" << endl;
    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_6
enter a number:
5
31 days in the month
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_6
enter a number:
2
28 days in the month
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_6
enter a number:
8
31 days in the month
*/