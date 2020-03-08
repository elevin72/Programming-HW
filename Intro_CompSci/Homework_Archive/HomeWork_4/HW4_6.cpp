/* 
File Name: HW4_6.cpp
Description of program: check if digits in number are descending by 1
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 4, question 6
Name: Eli Levin 341318228
Creation date: 27-11-19
Last Modification date: 27-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    int n = 0;
    cout << "enter a number:" << endl;
    cin >> n;
    while(n < 1)
    {
        cout << "ERROR" << endl;
        cin >> n;
    }

    bool descending = true; //now we must prove that n is not descending
    while (true)
    {
        int var1 = n % 10; // this gets the first value in n
        int var2 = (n / 10) % 10; //this gets the second value in n
        n /= 10; //this removes the first value of n
        if (n == 0) //if var2 is 0 then we know that the number has ended
        {
            break; //break the loop, stop everything because the number ended
        }
        if (var2 != var1 + 1)//and then test if var2 not equal to var1 + 1
        {
            descending = false;
            break;
        }
    }
    //now we test if we ever found descending to be false
    if (descending == true)
    {
        cout << "YES" << endl;
    }
    else 
    {
        cout << "NO" << endl;
    }    
    return 0;
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_6
enter a number:
654
YES

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_6
enter a number:
98765
YES

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_6
enter a number:
98756
NO

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_6
enter a number:
3
YES

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_6
enter a number:
0
ERROR
9
YES

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ g++ HW4_6.cpp -o HW4_6
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW4_6
enter a number:
432
YES
*/
