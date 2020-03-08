/* 
File Name: HW13_2.cpp
Description of program: Sort array recursively
Course Name: Introduction to Computer Science
Exercise# and Question#: 13, 3
Name: Eli Levin 341318228
Creation date: 30-1-20
Last Modification date:5-2-20
*/
#include <iostream>
using namespace std;

void swap(int* , int, int);
int smallest(int *arr , int n);
void sort(int *, int);
int main()
{
	int *arr;
	int num;
	do {
		cout << "enter a number:"<<endl;
		cin >> num;
		if (num<=0)
			cout << "ERROR" << endl;
	} while (num<=0);
	arr = new int[num];
	cout << "enter array values: ";
	for(int i = 0; i < num; i++)
		cin >> arr[i];
	cout << "before: \n";
	for(int i= 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	sort(arr, num);
	cout << "after: \n";
	for(int i= 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

void sort(int *arr, int n){
    if(n==1){
        return;
    }
    int min = smallest(arr, n); // this will take index of smallest number in our current array
    if(min != 0){ // if the smallest number is not in 0th place of currrent array (correct place), then swap it into the 0th place
        swap(arr, min, 0);
    }
    sort(arr+1, n-1); //and then  sort the next smaller array until base case is reached
}

void swap(int *a, int i, int j){
    int temp = a[i];
    a[i]= a[j];
    a[j] = temp;
}

int smallest(int *arr , int n){
    if(n == 1){
        return 0;
    }
    int min = smallest(arr+1, n-1) + 1;
    if (arr[min] <= arr[0]){
        return min;
    }
    else{
        return 0;
    } 
}

