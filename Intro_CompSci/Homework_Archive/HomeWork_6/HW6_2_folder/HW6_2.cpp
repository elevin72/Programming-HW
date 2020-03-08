/* 
File Name: HW6_2.cpp
Description of program: Encrypt file to output file
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 6, question 2
Name: Eli Levin 341318228
Creation date: 11-12-19
Last Modification date: 11-12-19
*/
#include <iostream>
#include <fstream>
using namespace std;

char Encrypt(char inch);

int main()
{ 
    ifstream fin("data.txt");
    ofstream fout("encoding.txt");

    if(!fin){
        cout << "Error reading file" << endl;
    } else {
        char nextch;
        while(fin >> noskipws >> nextch){ //doesn't skip whitespace
            fout << Encrypt(nextch); 
        }
    }

    fin.close();
    fout.close();
    return 0;

}

char Encrypt(char inch) { // inch stands for input char
    if(inch >= 'A' && inch <= 'Z'){
        return ('Z'-inch) + 'A'; //we want the char that is the distance from A that our given character was from Z
    } else if(inch >= 'a' && inch <= 'z'){
        return ('z'-inch) + 'a';
    }else if(inch >= '0' && inch <= '8'){
        return ++inch; // ++ prefixed will return the value after incrementing 1
    }else if(inch == '9') {
        return '0';
    } else {
        return inch;
    }
}
    