/* 
File Name: HW3_5
Description of program: sort 3 ints in ascending order
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 3 question 5
Name: Eli Levin 341318228
Creation date: 18-11-2019
Last Modification date: 18-11-2019
*/
#include <iostream>
using namespace std;

int main()
{ 
    int num1, num2, num3, smallest, middle, biggest;
	cout << "enter 3 numbers: " << endl;
	cin >> num1 >> num2 >> num3;

    //automatically assign order as if typed in correct order
    smallest = num1;
    middle = num2;
    biggest = num3;

    if (num1 <= num3 && num3 <= num2)
    {    
        smallest = num1;
        middle = num3;
        biggest = num2;
        
    }
    else if (num3 <= num1 && num1 <= num2)
    {
        smallest = num3;
        middle = num1;
        biggest = num2;
    }
    else if (num3 <= num2 && num2 <= num1)
    {
        smallest = num3;
        middle = num2;
        biggest = num1;
    }
    else if (num2 <= num1 && num1 <= num3)
    {
        smallest = num2;
        middle = num1;
        biggest = num3;
    }
    else if (num2 <= num3 && num3 <= num1)
    {
        smallest = num2;
        middle = num3;
        biggest = num1;
    }

	cout << smallest << " " << middle << " " << biggest << endl;
    return 0;
}
/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_5
enter 3 numbers: 
4 4 3
3 4 4
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_5
enter 3 numbers: 
-1
0
-2
-2 -1 0
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW3_5
enter 3 numbers: 
.75
0 22010 1501915376
*/