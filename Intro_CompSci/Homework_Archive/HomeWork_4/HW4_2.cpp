/* 
File Name: HW4_2
Description of program: test if 2 numbers are postive and then test user list against conditions set by the 2 numbers
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 4 question 2
Name: Eli Levin 341318228
Creation date: 25-11-19
Last Modification date: 25-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    bool loop = true;
    int a = -1;
    int b = -1;
    while (loop == true)
    {
        cout << "enter 2 positive numbers:" << endl;
        cin >> a;
        while (a <= 0) {
            cout << "ERROR" << endl;
            cin >> a;
        } 
        cin >> b;
        while (b <= 0) {
            cout << "ERROR" << endl;
            cin >> b;
        } 
        int list;
        int sum = 0;
        int amount = 0;

        cout << "enter a list of numbers: " << endl;

        while (sum <= a && amount < b)
        {
            cin >> list;
            sum += list;
            amount++;
        }
        cout << sum << endl;
        loop = false;
    }
    return 0;
}
/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_2
enter 2 positive numbers:
0 3
ERROR
4
enter a list of numbers: 
3 4 5
7
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ g++ HW4_2.cpp -o HW4_2
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_2
enter 2 positive numbers:
25
2
enter a list of numbers: 
4
5
9
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_2
enter 2 positive numbers:
4
7
enter a list of numbers: 
4
7
11
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_2
enter 2 positive numbers:
0
ERROR
-1
ERROR
-99     
ERROR
100
5
enter a list of numbers: 
30
49
26
105
*/