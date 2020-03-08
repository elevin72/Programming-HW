/* 
File Name: HW8_1.cpp    
Description of program: Search for number in array and return index if found
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 8 question 1
Name: Eli Levin 341318228
Creation date: 22/12/19
Last Modification date: 24/12/19
*/
int Search(const int arr[], int size, int num);

#include <iostream>
using namespace std;

int main()
{ 
    const int N = 10;
    int arr[N]; 
    

    cout << "enter 10 numbers:" << endl;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    //check for illegal numbers
    for (int i = 0; i < N-1; i++){
        if(arr[i] >= arr[i+1]){
            cout << "ERROR" << endl;
            for (int j = 0; j < N; j++){
                cin >> arr[j];
            }
            i = -1; // after we finish this loop and iterate, i will be 0 and start at the beginning of the array again
        }
    }

    int num;
    cout << "enter 1 number:" << endl;
    cin >> num;

    int index = Search(arr, N, num);// find index of num in array

    if(index == -1){// if num was not found in array
        cout << "not found" << endl;
    }
    else{
        cout << "the number " << num << " was found at index " << index << endl;
    }    

    return 0;
}

int Search(const int arr[], int size, int num){
    // set the top and bottom of where we're searching.
    int left = 0, right= size - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(arr[middle] == num){
            return middle;
        }

        // search to the left of middle
        if (num > arr[middle]){
            left = middle + 1;
            if(num > arr[right]){
                return -1;
            }
        }
        // search to the right of middle
        if (num < arr[middle]){
            right = middle - 1;
            if(num < arr[left]){
                return -1;
            }
        }
    }

    // if loop completed, the num doesn't exist in array
    return -1;
}

/*
enter 10 numbers:
1 2 3 4 5 6 7 8 9 10
enter 1 number:
2
the number 2 was found at index 1

enter 10 numbers:
1 2 3 4 5 6 7 8 9 10
enter 1 number:
11
not found
*/