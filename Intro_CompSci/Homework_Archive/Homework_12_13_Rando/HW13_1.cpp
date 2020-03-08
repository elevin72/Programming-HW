/* 
File Name: HW13_1.cpp
Description of program: recursively pritn A and B
Course Name: Introduction to Computer Science
Exercise# and Question#: 13, 1
Name: Eli Levin 341318228
Creation date: 30-1-20
Last Modification date: 5-2-20
*/

#include <iostream>
using namespace std;
void printABs(int n);
int main(){
	int num;
	cout << "enter a number:"<<endl;
	cin >> num;
	printABs(num);
	return 0;
}

void printABs(int n){
    if(n==0){ //base case
        return;
    }
    cout << "a"; //if base case wasn't true recurse on a until n=0. then print all the b's
    printABs(n-1);
    cout << "b";
}