/* 
File Name:
Description of program:
Course Name: Introduction to Computer Science
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date:
Last Modification date:
*/
#include <iostream>
using namespace std;

int smallest(int *arr , int n);
int main(){
	int * array;
	int num;
	do {
		cout << "enter a number:"<<endl;
		cin >> num;
		if (num<=0)
			cout << "ERROR" << endl;
	} while (num<=0);
	array = new int[num];
	cout << "enter array values: ";
	for(int i = 0; i < num; i++)
		cin >> array[i];
	cout << "the smallest is: " << array[smallest(array,num)]<< endl;
	return 0;
}

int smallest(int *arr , int n){
    if(n == 1){ //smallest number in an array of length 1 is in 0th index
        return 0;
    }
    int min = smallest(arr+1, n-1) + 1; // the following number 
    if (arr[min] <= arr[0]){ //if the following number is bigger than the current 0th number
        return min; //it will get passed back and incremented by 1 as the array grows back to correct size
    }
    else{
        return 0; //make the current 0th element the new min, when it gets returned a 1 will be added to it
    } 
}


