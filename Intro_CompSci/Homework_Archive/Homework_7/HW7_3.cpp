/* 
File Name: HW7_3.cpp
Description of program: program inputs array and deletes all repeats within that array
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 7 Question 3
Name: Eli Levin 341318228
Creation date: 14-12-19
Last Modification date: 18-12-19
*/
#include <iostream>
using namespace std;

void DelRepeat(int array[], int size);
void DelShift(int array[], int size, int del);

int main()
{ 
    const int N = 100;
    int vector[N] = {0};
    cout << "enter up to 100 values, to stop enter 0: " << endl;
    int num;
    cin >> num;

    for (int i = 0; i < N; i++)
    {
        if(num == 0){
            vector[i] == num;
            break;
        } else {
            vector[i] = num;
            cin >> num;
        }
    }

    DelRepeat(vector, N);

    cout << "the new vector is:" << endl;

    int count = 0;
    while(vector[count]){
        cout << vector[count] << " ";
        count++;
    }
    cout << endl << "number of elements: " << count << endl;

    return 0;

}

// this function will deleat all repeats of numbers in an array
void DelRepeat(int array[], int size){
    for (int i = 0; array[i] != 0; i++){ // for all elements in array until the element is 0
        for (int j = i+1; array[j] != 0; j++){ // compares each element with all following elements until we reach a 0
            if(array[j] == array[i]){ // if the two given elements are the same...
                DelShift(array, size, j);
                j--; // this line is necesary in case the value that replaced the element that was just deleted is ALSO a repeat, so we go and check it again.
            }
        }
    }   
}

/* delete elemnent from array and shift all elements over left until reaching a 0
del is the element to be deleted and where the shift begins
*/
void DelShift(int array[], int size, int del){ 
    for (int i = del; array[i] != 0 && i < size; i++){
        array[i] = array [i+1];
    }
}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_3
enter up to 100 values, to stop enter 0: 
31 31 31 4 6 7 0
the new vector is:
31 4 6 7 
number of elements: 4

eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_3
enter up to 100 values, to stop enter 0: 
31 4 5 7 8 31 0
the new vector is:
31 4 5 7 8 
number of elements: 5
*/
