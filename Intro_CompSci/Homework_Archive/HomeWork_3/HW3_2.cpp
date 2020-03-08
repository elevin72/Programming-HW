/* 
File Name: HW3_2
Description of program: test if number is within range or not
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercize 3, question 2
Name: Eli Levin 341318228
Creation date: 18-11-2019
Last Modification date: 18-11-2019
*/
#include <iostream>
using namespace std;

int main()
{ 
    int startRange, endRange, num;
    cout << "enter 3 numbers" << endl;
    cin >> startRange >> endRange >> num;

    if (num < startRange) 
    {
        cout << "smaller" << endl;
    }
    else if (num > endRange)
    {
        cout << "bigger" << endl;
    }
    else if (num >= startRange && num <= endRange)
    {
        cout << "between" << endl;
    }
    
    
    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_2
enter 3 numbers
2
5
3
between
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_2
enter 3 numbers
-1
1
0
between
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_2
enter 3 numbers
0
0
0
between
*/