/* 
File Name: HW4_5.cpp
Description of program: make a triangle of numbers
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 4, question 5
Name: Eli Levin 341318228
Creation date: 27-11-19
Last Modification date: 27-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 

    int n = 0;
    cout << "enter a one digit number:" << endl;
    cin >> n;
    while (n <= 0)
    {
        cout << "ERROR" << endl;
        cin >> n;
    }    
        int num = n;
        //line loop -- iterates each line
        while (num > 0)
        {
            int diff = n - num;
            //space loop -- prints correct number of spaces
            while (diff > 0) 
            {
                cout << "   ";
                diff--;
            }
            //number loop -- print correct numbers
            for (int i = num; i > 0; i--)
            {
                if (i > 1) 
                {
                    cout << i << ", ";
                }
                else if (i == 1)//if i=1, then dont print a comma, instead print a newline
                {
                    cout << 1 << endl;
                } 
            }
            num--;
        }
    return 0;
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_5
enter a one digit number:
4
4, 3, 2, 1
   3, 2, 1
      2, 1
         1

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_5
enter a one digit number:
6    
6, 5, 4, 3, 2, 1
   5, 4, 3, 2, 1
      4, 3, 2, 1
         3, 2, 1
            2, 1
               1

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_5
enter a one digit number:
0
ERROR
1
1

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_5
enter a one digit number:
9
9, 8, 7, 6, 5, 4, 3, 2, 1
   8, 7, 6, 5, 4, 3, 2, 1
      7, 6, 5, 4, 3, 2, 1
         6, 5, 4, 3, 2, 1
            5, 4, 3, 2, 1
               4, 3, 2, 1
                  3, 2, 1
                     2, 1
                        1

*/