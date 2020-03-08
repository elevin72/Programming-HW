/* 
File Name: HW8_2.cpp    
Description of program: Merge 3 descending arrays
Course Name: Introduction to Computer Science
Exercise# and Question#: Exercise 8 question 2
Name: Eli Levin 341318228
Creation date: 22/12/19
Last Modification date: 24/12/19
*/
#include <iostream>
using namespace std;

void AssignArr(int array[], int size);
void MergeArrays(const int arr1[], const int arr2[], int merge[], int s1, int s2, int s3);
void ArrPositive(int arr[], int size);

int main()
{ 
    const int N = 10;
    int arr1[N] = {0}, arr2[N] = {0}, arr3[N] = {0};

    cout << "enter values for the first vector:" << endl;
    AssignArr(arr1, N);
    cout << "enter values for the second vector:" << endl;
    AssignArr(arr2, N);
    cout << "enter values for the third vector:" << endl;
    AssignArr(arr3, N);

    int sub[2*N] = {0};
    MergeArrays(arr1, arr2, sub, N, N, 2*N);

    int merge[3*N] = {0}; // 30 because that is maximum number that we could have if merged all elements of the 3 arrays
    MergeArrays(arr3, sub, merge, N, 2*N, 3*N);


    cout << "merged vector is:" << endl;
    for (int i = 0; i < 3*N && merge[i] != 0; i++){
        cout << merge[i] << " ";
    }
    cout << endl;

    return 0;

}


//function inputs non-zero numbers to an array, and then checks if was descending or not
void AssignArr(int arr[], int size) {
    ArrPositive(arr, size);
    // now check all inputs were correct
    for (int i = 0; i < size-1 && arr[i] != 0; i++){
        if(arr[i] <= arr[i+1] && arr[i+1] != 0){ //if it was not descending or we reached a zero
            cout << "ERROR"  << endl; // print error
            ArrPositive(arr, size); //reassign entire array       
            i = -1; // re-start the check loop    
        }
        
    }
}

//function inputs only non-zero numbers
void ArrPositive(int arr[], int size){
    int num;
    for(int i = 0; i < size; i++) {
        cin >> num;
        arr[i] = num;
        if(num == 0)
            break;
    }
}

//function merges 2 arrays in non-ascending order (descending)
void MergeArrays(const int arr1[], const int arr2[], int merge[], int s1, int s2, int s3){ 
    int i1 = 0, i2 = 0, m = 0; 
  
    // Check if still within both arrays, AND if either array has reached zero, since we stop for zeros
    while (i1 < s1 && i2 < s2 && arr1[i1] != 0 && arr2[i2] != 0) { 
        
        //If current element of arr1 is bigger than current element of arr2, put current arr1[] in merge and increment arr1 and merge index's. /
        if (arr1[i1] >= arr2[i2]) 
            merge[m++] = arr1[i1++];
        if(arr2[i2] >= arr1[i1]) //Do same with second array 
            merge[m++] = arr2[i2++];
    } 
    // Store remaining elements of first array 
    while (i1 < s1 && arr1[i1] != 0) 
        merge[m++] = arr1[i1++]; 
  
    // Store remaining elements of second array 
    while (i2 < s2 && arr2[i2] != 0) 
        merge[m++] = arr2[i2++]; 
} 

/*
enter values for the first vector:
3
2
1
0
enter values for the second vector:
5
4
3
0
enter values for the third vector:
7
6
5
0
merged vector is:
7 6 5 5 4 3 3 2 1 
*/

