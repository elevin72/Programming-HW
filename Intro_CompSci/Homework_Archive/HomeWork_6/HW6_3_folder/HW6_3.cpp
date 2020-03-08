/* 
File Name: HW6_3.cpp
Description of program: Find average of files and say which file is biggest
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 6, question3
Name: Eli Levin 341318228
Creation date: 11-12-19
Last Modification date: 11-12-19
*/
#include <iostream>
#include <fstream>
using namespace std;
float FileAverage(ifstream&);

int main()
{ 


    //open 4 files
    ifstream fin1("grades1.txt");
    ifstream fin2("grades2.txt");
    ifstream fin3("grades3.txt");
    ifstream fin4("grades4.txt");

    //get the average of each file
    float average1 = FileAverage(fin1);
    float average2 = FileAverage(fin2);
    float average3 = FileAverage(fin3);
    float average4 = FileAverage(fin4);

    // put the bigger of 1 and 2 into a
    float a = average1 > average2 ? average1 : average2;
    // put the bigger of 3 and 4 into b
    float b = average3 > average4 ? average3 : average4;
    // put bigger of a and b into max
    float max = a > b ? a : b;

    // if highest average equals max, then print corresponding file index
    cout << "highest average found in file ";
    if(max == average1){
        cout << "1" << endl;
    } else if(max == average2){
        cout << "2" << endl;
    } else if(max == average3){
        cout << "3" << endl;
    } else if(max == average4){
        cout << "4" << endl;
    } else {
        cout << endl << "!!! ERROR" << endl;
    }
    return 0;
}

float FileAverage(ifstream& fin) {
    float num, sum=0, counter=0, average;
    if(!fin){
        cout << "Error reading file" << endl;
        return -1;
    }
        while(fin >> num){
            sum += num;
            counter++;
        }
    average = sum / counter;
    return average;
}