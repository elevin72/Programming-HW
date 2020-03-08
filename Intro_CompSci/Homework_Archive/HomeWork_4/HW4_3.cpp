/* 
File Name: HW4_4.cpp
Description of program: write fibonacci until n+1
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 4 question3
Name: Eli Levin 341318228
Creation date:  25-11-19
Last Modification date: 25-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    int n;
    cout << "enter a number:" << endl;
    cin >> n;
    while (n < 0)
    {
        cout << "ERROR";
        cin >> n;
    }

    int fib1 = 0;
    int fib2 = 1;
    int nextFib;

    if (n==0)
        cout << fib1 << endl;
    if (n==1)
        cout << fib1 << " " << fib2 << endl;
    if (n > 1) {
        int counter = 2;
        cout << fib1 << " " << fib2 << " ";
        while (n >= counter) {
            nextFib = fib1 + fib2;
            cout << nextFib << " ";
            fib1 = fib2;
            fib2 = nextFib;
            counter++;
        }
    }
    cout << endl;
    return 0;
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_3
enter a number:
0
0

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_3
enter a number:
1
0 1

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_3
enter a number:
2
0 1 1 
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_3
enter a number:
3    
0 1 1 2 
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_3
enter a number:
4
0 1 1 2 3 
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_3
enter a number:
10
0 1 1 2 3 5 8 13 21 34 55
*/