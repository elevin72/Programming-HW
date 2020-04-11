/* 
Program Name: Date Manipulator
Description of program: Manipulates dates
Course Name: C++ Workshops
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date: 11/04/2020
Last Modification date:
*/
#include <iostream>
#include "date.h"
using namespace std;


int main()
{ 
    cout << "Enter a date" << endl;
    int d,m,y;
    char slash;
    cin >> d >> slash >> m >> slash >> y;
    Date myDate(d,m,y);
    cout << myDate << endl;
    Date otherDate;
    int choice;
    do
    {
        cout << "What do you want to do" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter a date" << endl;
            cin >> myDate;
            cout << myDate << endl;
            break;
        case 2:
            cout << ++myDate << endl;
            break;
        case 3:
            cout << myDate++ << endl;
            break;
        case 4:
            int x;
            cout << "Enter #days" << endl;
            cin >> x;
            cout << (myDate += x) << endl;
            break;
        case 5:
            cout << "Enter a date" << endl;
            cin >> otherDate;
            cout << ">: " << (myDate > otherDate ? "true" : "false") << endl;
            break;
        case 6:
            cout << "Enter a date" << endl;
            cin >> otherDate;
            cout << "<: " << (myDate < otherDate ? "true" : "false") << endl;
            break;
        case 7:
            cout << "Enter a date" << endl;
            cin >> otherDate;
            cout << "==: " << (myDate == otherDate ? "true" : "false") << endl; 
            break;
        default:
            break;
        }
    } while (choice != -1);
    

    return 0;

}
