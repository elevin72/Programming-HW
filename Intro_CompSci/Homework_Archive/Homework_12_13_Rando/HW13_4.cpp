/* 
File Name: HW13_4.cpp
Description of program: Reverse array recursively
Course Name: Introduction to Computer Science
Exercise# and Question#: 13,4
Name: Eli Levin 341318228
Creation date: 5-2-20
Last Modification date: 5-2-20
*/
#include <iostream>
using namespace std;

void swap(int*, int, int);
void reverse(int *, int);
int main(){
	int * arr;
	int num;
	cout << "enter a number: ";
	cin >> num;
	arr = new int[num];
	cout << "enter array values: ";
	for(int i = 0; i < num; i++)
		cin >> arr[i];
	
	cout << "before: \n";
	for(int i= 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	reverse(arr, num);
	cout << "after: \n";
	for(int i= 0; i < num; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}

void reverse(int *arr, int n){
    if(n <= 1){
        return;
    }
    swap(arr, 0, n-1); //swap first and last place
    reverse(arr+1, n-2); //and call again for next 2 places closer to the center
}

void swap(int *a, int i, int j){
    int temp = a[i];
    a[i]= a[j];
    a[j] = temp;
}