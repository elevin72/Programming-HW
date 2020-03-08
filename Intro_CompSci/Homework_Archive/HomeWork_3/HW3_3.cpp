/* 
File Name: HW3_3
Description of program: input 2 numbers and operator and perform correct operation
Course Name: Introduction to Computer Science
Exercise# and Question#: Exersise 3 Question 3
Name: Eli Levin 341318228
Creation date: 18-11-2019
Last Modification date: 18-11-2019
*/
#include <iostream> 
using namespace std;

int main()
{ 
    int num1, num2;
    float result;
    char oper;
    cout << "enter 2 numbers:" << endl;
    cin >> num1 >> num2;
    cout << "enter an operator:" << endl;
    cin >> oper;

    switch (oper)
    { 
    case '+':
        result = num1 + num2;
        break;

    case '-':
        result = num1 - num2;
        break;

    case '*':
        result = num1 * num2;
        break;

    case '/':
        result = (float)num1 / num2;
        break;
    
    default: cout << "ERROR" << endl;
        return 0;
        break;
    }

    cout << num1 << " " << oper << " " << num2 << " = " << result << endl;
    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_3
enter 2 numbers:
9 2 
enter an operator:
/
9 / 2 = 4.5
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_3
enter 2 numbers:
5
4
enter an operator:
*
5 * 4 = 20
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_3
enter 2 numbers:
0
0
enter an operator:
/
0 / 0 = -nan
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_3
enter 2 numbers:
5
0
enter an operator:
/
5 / 0 = inf
*/