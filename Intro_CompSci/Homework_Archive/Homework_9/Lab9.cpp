/* 
File Name:
Description of program:
Course Name: Introduction to Computer Science
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date:
Last Modification date:
*/
#include <iostream>
using namespace std;

int main()
{ 
    int i = 24; //in address 1000
    int* ptr = &i;

    ptr++;
    *ptr++;
    *(ptr + 1);
    (*ptr)++;
    *(ptr++);
    ptr + 1;
    (ptr++);

    return 0;

}