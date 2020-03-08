/* 
File Name: HW7_4.cpp
Description of program: Find indices of an array of number and output those indices
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 7 Question 4
Name: Eli Levin 341318228
Creation date: 15-12-19
Last Modification date: 18-12-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    const int N = 6;
    float numbers[6];
    int indices[6] = {0};

    cout << "enter 6 numbers between 0 and 1:" << endl;
    for (int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    //check for illegal numbers
    for (int i = 0; i < N; i++){
        if(numbers[i] <= 0 || numbers[i] >= 1){
            cout << "ERROR" << endl;
            for (int j = 0; j < N; j++){
                cin >> numbers[j];
            }
            i = -1; // after we finish this loop and iterate, i will be 0 and start at the beginning of the array again
        }
    }

    /* In this loop, the number 1 is used as a sign and placeholder in the array. 
    We need a placeholder in order to keep the form of the array, and not move any elements even after finding smallest values
    The number 1 was chosen since it's bigger than all the other numbers in the array, and can be identified as not what the user entered
    */
    for(int i = 0; i < N; i++){ // int i is associated with indices
        float min = 1; //initialize our minimum value as 1, bigger than any number that it will come across in our array
        for (int j = 0; j < N; j++){ // int j is associated with numbers  
            if(min > numbers[j]){ 
                min = numbers[j]; // make min the number that was smaller than our old min
                indices[i] = j; // set the current place in indices equal to the place where we found smallest number.
            }
        }
        numbers[indices[i]] = 1; //  Set whatever number was found to be smallest in that pass, and make it 1 i.e, bigger than the biggest number in the array.
    }

    cout << "sorted indices:" << endl;
    for (int i = 0; i < N; i++){
        cout << indices[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_4
enter 6 numbers between 0 and 1:
.55 .32 .44 .1 .6 .2
sorted indices:
3 5 1 2 0 4 

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_4
enter 6 numbers between 0 and 1:
.2 .3 .4 .5 .6 .7
sorted indices:
0 1 2 3 4 5 
*/















