/* 
Program Name: Rational Operators
Description of program: Overload some operators for the Rational class 
Course Name: C++ Workshops
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date: 02/04/2020
Last Modification date:
*/
#include "rational.h"
#include <iostream>
using namespace std;

int main()
{ 
    int num, denom;
    cout << "Enter two rational numbers" << endl << "a: ";
    cin >> num;
    cin.ignore(1, '/');
    cin >> denom;
    Rational a(num, denom);
    cout << "b: ";
    cin >> num;
    cin.ignore(1, '/');
    cin >> denom;
    Rational b(num, denom);

    //Rational temp = b - a;
    cout << "b-a: " << b-a << endl;
    //temp.Print();

    cout << "a!=b: " << (a!=b ? "true" : "false") << endl;

    cout << "a<b: " << (a<b ? "true" : "false") << endl;

    cout << "a>b: " << (a>b ? "true" : "false") << endl;

    cout << "a>=b: " << (a>=b ? "true" : "false") << endl;

    cout << "a++: " << a++ << endl;
    //a++.Print();
    
    cout << "--a: " << --a << endl;
    //--a.Print();

    cout << "a--: " << a--<< endl;
    //a--.Print();

    b = a;

    //temp = b-a;
    cout << "b-a: " << b-a << endl;
    cout << "b/a: " << b/a << endl;
    cout << "a!=b: " << (a!=b ? "true" : "false") << endl;
    cout << "a<b: " << (a<b ? "true" : "false") << endl;
    cout << "a>=b: " << (a>=b ? "true" : "false") << endl;




    



    return 0;

}