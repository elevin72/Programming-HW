/* 
File Name: HW8_4.cpp
Description of program: Sort 10 5 letter strings alphabetically
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 8 question 4
Name: Eli Levin 341318228
Creation date: 24/12/19
Last Modification date: 25/12/19
*/
#include <iostream>
using namespace std;

const int N = 5;

void BubbleSort(char arr[][N], int size, int start);
void Swap(char& x, char& y);

int main()
{ 
    char arr[2*N][N];

    cout << "enter 10 words:" << endl;
    //input 10 seperate 5 letter strings
    for (int i = 0; i < 2*N; i++){
        for (int j = 0; j < N; j++){
            cin >> arr[i][j];
        }   
    }

    // Bubblesort 5 times, each time focusing on a more important letter
    for (int i = N-1; i >= 0; i--){
        BubbleSort(arr ,2*N, i);
    }
    cout << "after sorting:" << endl;

    // print array of strings
    for (int i = 0; i < 2*N; i++){
        if(i){
            cout << " ";
        }
        for (int j = 0; j < N; j++){
            cout << arr[i][j];
        }   
    }
    cout << endl;

    return 0;
}


 //This function will bubble sort arrays of strings based on the relative position of 'compare' in all the strings
 void BubbleSort(char arr[][N], int size, int compare){
    bool sorted;
    int count = 0; //count will let us know how many times we have looped through, remove one more iteration from our 'i' loop each pass through
    //this works because after each pass through the loop we know that one more element, starting from the last element is in correct place
    do {
        sorted = true; //assume sorted until proven otherwise 
         for (int i = 0; i < (2*N)-count-1; i++){ // loop through until we reach what we already know to be correct 
            if(arr[i][compare] > arr[i+1][compare]){ // if the 'compare' element of current string is bigger(lower alphabetically) than the 'compare' element of the next string... 
                for (int j = 0; j < N; j++){ 
                    Swap(arr[i][j], arr[i+1][j]);// ...then swap the strings, character by character
                }
                sorted = false; // and if we're in this if statement, that means that we're not sorted and we should go through the loop again   
            }
         }
         count++;
    } while (!sorted); // if we ever complete the loop and do not find any strings out of order, finish looping
}

// swaps 2 characters
void Swap(char& x, char& y){
    char t = x;
    x = y;
    y = t;
}

/*
enter 10 words:
words
zebra
turds
turnt
flown
floor
broom
brown
total
candy
after sorting:
broom brown candy floor flown total turds turnt words zebra
*/

