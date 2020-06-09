/* 
Program Name: String
Description of program: make your own string library
Course Name: C++ Workshops
Exercise# and Question#: Exercise 3 question 3
Name: Eli Levin 341318228
Creation date: 12/04/2020
Last Modification date:16/04/2020
*/

//I had issues with Moodle for this problem. Moodle inputted a space before the first string but then didn't expect a space to be there.
//See below for my examples of the the moodle tests that I "failed"

#include <iostream>
#include "string.h"
using namespace std;

int main()
{ 
    char x[80], y[80];
    int n;
    cin.ignore(1);
    cin.getline(x, 80);
    cin.getline(y, 80);
    cin >> n;
    String a(x), b(y);
    if(a < b){
        cout << "a<b" << endl;
    } else if(a > b) {
        cout << "a>b" << endl;
    } else if(a == b){
        cout << "a=b" << endl;
    }
    a.insert(n, b); //insert() has a print built into it.
    return 0;
}

/*************EXAMPLES***************

Hello
World
2
a<b
WoHellorld

Hello
Hello
2
a=b
HeHellollo

World
Hello
2
a>b
HeWorldllo

World
World
5
a=b
WorldWorld

*/

