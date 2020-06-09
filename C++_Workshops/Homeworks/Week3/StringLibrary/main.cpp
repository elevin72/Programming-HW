/* 
Program Name: String Library
Description of program: Learn the c++ standard string library
Course Name: C++ Workshops
Exercise# and Question#: Exercise 3 question 4
Name: Eli Levin 341318228
Creation date: 13/04/2020
Last Modification date: 16/04/2020
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{ 
    string str;
    getline(cin,str);
    // loop will replace all spaces with stars
    for(int i = 0; i < str.length(); ++i){
        if(str[i] == ' '){
            str[i] = '*';
        }
    }
    cout << str << endl;

    // replace the d's with the other stuff
    str.erase(str.find_first_of('d'), 3) += "#!!@1234";

    cout << str << endl;

    //delete the beginning of the loop repeatedly and print
    for(int i = 0; i < 3; ++i){
        str.erase(0,4);
        cout << str << endl;
    }

    return 0;

}