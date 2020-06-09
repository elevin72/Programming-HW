/* 
Program Name:Linked List
Course Name: C++ Workshops
Exercise# and Question#: Exercise 5, question 1
Name: Eli Levin 341318228
Creation date: 24/05/2020
Last Modification date:
*/

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	List lst;
	int choice,val;
	cout<<"enter the list values\n";
	cin>>lst;
	cout<<"choose 0-2\n";
	cin>>choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:cout<<"enter a value to insert\n";
			cin>>val;
			lst.Insert(val);
			break;
		case 2:cout<<"enter a value to remove\n";
			cin>>val;
			try{
				lst.Delete(val);
			}
			catch(string e)
			{
				cout<<e << endl;
			}
			break;
		default:cout<<"ERROR\n";
		}
		cout<<lst<<endl;
		cout<<"choose 0-2\n";
		cin>>choice;
	}
	return 0;
}

