/* 
File Name: HW7_5.cpp
Description of program: Subtract sets from each other and output difference
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 7 Question 5
Name: Eli Levin 341318228
Creation date: 16-12-19
Last Modification date: 18-12-19
*/
#include <iostream>
using namespace std;

void InArr(int array[], int size);

int main()
{ 
    const int N = 6;
    int set1[N];
    int set2[N];
    int difference[N];
    

    cout << "enter first 6 numbers:" << endl;
    InArr(set1, N);

    cout << "enter next 6 numbers:" << endl;
    InArr(set2, N);

    int place = 0; // to be used to define what place of difference[] we're up to
    for (int i = 0; i < N; i++){
        bool match = false;
        for (int j = 0; j < N; j++){
            if(set1[i] == set2[j]){
                match = true;
            }
        }
        if(match == false){
            difference[place] = set1[i];
            place++;
        }
    }

    cout << "set difference is:" << endl;
    if(place == 0){
        cout << "empty" << endl;
    } else {
        for (int i = 0; i < place; i++){
            cout << difference[i] << " ";
        }
    }
    cout << endl;   
    return 0;
}

// this functions inputs numbers to array and checks at each number if it was positive or not
void InArr(int array[], int size){
    for (int i = 0; i < size; i++){
        int num;
        cin >> num;
        while(num <= 0){
            cout << "ERROR" << endl << "enter new number" << endl;
            cin >> num;
        }
        array[i] = num;
    }
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_5
enter first 6 numbers:
1 2 3 4 5 6
enter next 6 numbers:
4 5 6 7 8 9
set difference is:
1 2 3
*/