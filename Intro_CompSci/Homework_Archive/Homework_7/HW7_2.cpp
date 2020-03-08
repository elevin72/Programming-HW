/* 
File Name: HW7_2.cpp
Description of program: See how many times an array is found in another array
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 7 question 2
Name: Eli Levin 341318228
Creation date: 14-12-19
Last Modification date: 18-12-19
*/
#include <iostream>
using namespace std;

int ArrSize(int min, int max);
void AssignArr(int array[], int size);

int main()
{ 

    int vector1[500], vector2[100];
    int size1, size2;

    //ask for size of vector1
    cout << "enter size of first array" << endl;
    size1 = ArrSize(1, 500);
    //Assign values up until user inputted size
    cout << "enter first array values" << endl;
    AssignArr(vector1, size1);

    //AssignArr(vector1, size1);

    //same for vector2
    cout << "enter size of second array" << endl;
    size2 = ArrSize(1, 100);
    cout << "enter second array values" << endl;
    AssignArr(vector2, size2);


    /*To accomplish the next check, we need to compare vector2 with every place of vector1, i.e.,
    does vector1 match with vector2 if you start from element 0; does vector1 match with vector2 if 
    you start from element 1; and so on...
    */
    int counter; // counter is the number we actually want to print, i.e, the number of times vector2 is found inside of vector1 

    for (int i = 0; i < size1; i++){
        for (int j = 0;  j < size2 ; j++) 
        {
            if(vector1[i + j] != vector2[j]){ // we check for the negative -- is the element in vector1 NOT equal to the corresponding element of vector2
                break; // then stop checking for vector[i] against vector2, and start the next i
            }
            if(j == size2-1){//if we've finished the size of vector2 without breaking, that means we've found an instance of vector2 inside vector1, and we up counter
                counter++;
            }
        }
    }
    cout << "result: " << counter << " times" << endl;

    return 0;
}

//Asks user for input and makes sure it's within the defined range of an array
int ArrSize(int min, int max) {
    int ins;
    while(true) {
        cin >> ins;
        if(ins >= min && ins <= max){
            return ins;
        } else {
            cout << "ERROR" << endl;
        }
    }
}

//assigns values for elements in array until the size is reached
void AssignArr(int array[], int size) {
    for(int i = 0; i < size; i++) {
        cin >> array[i];
    }
}



/*
Step 1. Define 2 arrays, of size 500, 100.
Step 2. Ask user how many elements they'd like to fill = size1, size2,
        Must be within defined range of array(i.e. 1-500)
Step 3. Loop through array from 0 to size - 1, and ask for inputs 
Step 4. repeat for second array.
Step 5. Loop inside a loop?
            Look for the complete second array inside the first array
            To side step problem of overlapping arrays, like in example 2, make a variable that keeps track of where the current array is checking.
Step 6. Print that number.
*/

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./HW7_2
enter size of first array
11
enter first array values
1
2
1
2
1
2
1
2
1
2
1
enter size of second array
3
enter second array values
1
2
1
result: 5 times
*/