/* 
File Name: HW5_4.cpp
Description of program: Find next smallest prime number
Course Name: Introduction to Computer Science
Exercise# and Question#: 5.4
Name: Eli Levin 341318228
Creation date: 3-12-19
Last Modification date: 3-12-19
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool isPrime(int num);
int findPrime(int num);

int main()
{ 
    int num; 
    cout << "enter number of values:" << endl;
    cin >> num;
    srand((unsigned)time(NULL));
    
    if(num <= 0)
    {
        cout << "table size: " << findPrime(rand()%90 + 10) << endl;
    }
    else
    {
        cout << "table size: " << findPrime(num) << endl;
    }
}

bool isPrime(int num)
{
    if (num % 2 == 0 && num != 2 || num == 1)
    {
        return false;
    }
    int biggestFactor = num / 3; // biggest possible factor would be co-factor of 3, since we already removed even numbers
    for(int i = 2; i <= biggestFactor; i++)
    {
        int factor = num / i;
        if(num == i * factor)
        {
            return false;
        }
    }
    return true;
    
}

int findPrime(int num)
{
    while(isPrime(num) == false)
        num++;
    return num;
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW5_4
enter number of values:
120
table size: 127

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW5_4
enter number of values:
0
table size: 19
*/