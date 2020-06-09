/* 
File Name: HW8_3.cpp
Description of program: Sorts upper right triangle and lower left triangle of a matrix seperately 
Course Name: Introduction to Computer Science
Exercise# and Question#: exercise 8 question 3
Name: Eli Levin 341318228
Creation date: 23/12/19
Last Modification date: 23/12/19
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
const int N = 10;

void Sort(int arr[], int size);
void PrintArray(const int arr[][N]);


int main()
{
        // Although not specifically asked for, I had my program insert 100 random numbers into the file at the beginning
    srand(time(nullptr));

    ofstream fout("textHW8_3");
    for (int i = 0; i < 100; i++){
        fout << rand()%90 + 10 << " "; // numbers chosen because all are 2 digit, so the spacing stays nice in the output
    }
    fout.close();

    //create input file stream
    ifstream fin("textHW8_3");
    int matrix[N][N];
    
    //read in matrix from file
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            fin >> matrix[i][j];
        }
    } 

    // print array while random
    cout << "before sorted" << endl;
    PrintArray(matrix);
    cout << endl;

    // take the top right triangle and put it into a 1D array 
    const int N1 = 45; // 45 is the amount of numbers in each triangle
    int triangle[N1];
    int count = 0;
    for(int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            triangle[count++] = matrix[i][j];
        } 
    }
    // now sort the array
    Sort(triangle, N1);
    // reinsert array into where where it came from
    count = 0;
    for(int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            matrix[i][j] = triangle[count++];
        }
    }

    // Now we do the same procedure, but for the bottom left
    // We'll take the numbers backwards though, in order to always end our loop when j is at 0. 
    //This is ok to do as long as we add the array back in in the same order that we took it out
    count = N1-1;
    for(int i = N-1; i > 0; i--){
        for(int j = i-1; j >= 0; j--){
            triangle[count--] = matrix[i][j];
        }
    }
    // sort the 1D array
    Sort(triangle, N1);
    // reinsert array into places where it came from
    count = N1-1;
    for(int i = N-1; i > 0; i--){
        for(int j = i-1; j >= 0; j--){
            matrix[i][j] = triangle[count--];
        }
    }

    cout << "sorted matrix" << endl;
    PrintArray(matrix);
    cout << endl;

    return 0;
}

// sorts an array with insertion sort
void Sort(int arr[], int size){
    for (int i = 1; i < size; i++){
        // take current value which we're checking this itiration
        int val = arr[i];
        int j=i;
        // loop until we've reached the zeroth element OR the next element is smaller than val.
        for (; j > 0 && val < arr[j-1]; j--){
            arr[j] = arr[j-1]; // shift over one
        }  
        arr[j] = val; //then put val in before we found the first number bigger than it
    } 
}

// prints 2D array in a matrix format
void PrintArray(const int arr[][N]){
    for (int i = 0; i < N; i++){
        if(i != 0)
            cout << endl;
        for (int j = 0; j < N; j++){
            cout << arr[i][j] << "   ";
        }
    } 
}

/*
before sorted
30   96   48   97   31   25   47   83   51   86   
67   98   73   44   34   31   56   75   46   35   
56   46   70   92   39   51   30   63   48   85   
27   68   82   88   66   15   36   37   88   11   
46   79   10   21   46   34   64   92   32   33   
28   78   70   21   72   10   85   25   85   34   
11   36   25   17   25   14   22   51   63   33   
52   11   13   74   44   49   31   98   65   53   
32   16   55   25   50   50   25   36   65   12   
82   89   38   97   96   75   12   41   49   66   
sorted matrix
30   11   12   15   25   25   30   31   31   32   
10   98   33   33   34   34   34   35   36   37   
11   11   70   39   44   46   47   48   48   51   
12   13   14   88   51   51   53   56   63   63   
16   17   21   21   46   64   65   66   73   75   
25   25   25   25   27   10   83   85   85   85   
28   31   32   36   36   38   22   86   88   92   
41   44   46   46   49   49   50   98   92   96   
50   52   55   56   67   68   70   72   65   97   
74   75   78   79   82   82   89   96   97   66  

*/