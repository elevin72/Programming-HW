/* 
File Name: HW6_1.cpp
Description of program: read from 2 files and print to a 3rd
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 6 question1
Name: Eli Levin 341318228
Creation date: 8-12-19
Last Modification date: 9-12-19
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() { 

	ifstream id("id.txt");
    ifstream grades("grades.txt");
	ofstream roster("roster.txt");

    int idNum, gradesNum;
    while(id >> idNum && grades >> gradesNum){
        roster << idNum << " ";
        roster << gradesNum << endl;
    }

    int nextNum;
    if(!grades.eof()){ //if grades did not finsh reading file then id did
        cout << "finished reading id before grades" << endl;
        while(grades >> nextNum){
            cout << nextNum << endl;
        }
    }
    if(!id.eof()){ //if id did not finsh reading file then gardes did
        cout << "finished reading grades before id" << endl;
        while(id >> nextNum) {
            cout << nextNum << endl;
        }
    }
    return 0;
}
