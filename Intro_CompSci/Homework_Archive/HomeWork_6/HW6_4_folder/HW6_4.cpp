/* 
File Name: HW6_4.cpp
Description of program: Find frequency on digit in file and output to file
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 6, question 6
Name: Eli Levin 341318228
Creation date: 11-12-19
Last Modification date: 11-12-19
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{ 
    ifstream fin("information.txt");
    ofstream fout("frequencyDigits.txt");

    char ch;
    int c0=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0; //where c stands for counter
    while(fin >> ch) {
        switch (ch)
        {
        case '0':
            c0++;
            break;
        case '1':
            c1++;
            break;
        case '2':
            c2++;
            break;
        case '3':
            c3++;
            break;
        case '4':
            c4++;
            break;
        case '5':
            c5++;
            break;
        case '6':
            c6++;
            break;
        case '7':
            c7++;
            break;
        case '8':
            c8++;
            break;
        case '9':
            c9++;
            break;
        default:
            break;
        }
    }

    fout << "digit frequency" << endl;
    fout << "0     " << c0 << endl;
    fout << "1     " << c1 << endl;
    fout << "2     " << c2 << endl;
    fout << "3     " << c3 << endl;
    fout << "4     " << c4 << endl;
    fout << "5     " << c5 << endl;
    fout << "6     " << c6 << endl;
    fout << "7     " << c7 << endl;
    fout << "8     " << c8 << endl; 
    fout << "9     " << c9 << endl;

    return 0;
}