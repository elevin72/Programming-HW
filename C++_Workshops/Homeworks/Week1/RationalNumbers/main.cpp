/* 
File Name: RationalNumbers
Description of program: Takes 2 rational numbers and outputs if equal or not
Course Name: C++ Workshops
Exercise# and Question#: 1, 1
Name: Eli Levin 341318228
Creation date: 03/03/20
Last Modification date: 05/03/20
*/

//This is a change
#include <iostream>
#include "rational.h"
using namespace std;

int main()
{ 
    
    //get user data
    cout << "enter two rational numbers" << endl;
    int num, denom;
    cin >> num;
    cin.ignore(1, '/');
    cin >> denom;
    Rational frac1(num, denom);

    cin >> num;
    cin.ignore(1, '/');
    cin >> denom;
    Rational frac2(num, denom);

    //if fraction 1 is equal to fraction 2
    if(frac1.Equal(frac2)){
        cout << "equal" << endl;
    }
    else {
        cout << "different" << endl;
        frac1.Print();
        cout << " ";
        frac2.Print();
        cout << endl;
    }

    return 0;
}
