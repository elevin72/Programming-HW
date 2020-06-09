/* 
Program Name: Linked List
Course Name: C++ Workshops
Exercise# and Question#: Exercise 5, question 2
Name: Eli Levin 341318228
Creation date: 24/05/2020
Last Modification date:
*/

#include <iostream>
#include "List.h"
using namespace std;

List Merge(const List L1, const List L2){ 
    List L3;
    L3 = L1;
    List::Node* pos = L2._head;
    while(pos != NULL){
        L3.Insert(pos->_key);
        pos = pos->_next;
    }
    return L3;
}

void MakeSet(List l){
    List::Node* pos = l._head->_next;
    if(l.IsEmpty() || pos == NULL){
        return;
    }
    List::Node* prev = l._head;
    while(pos != NULL){
        if(pos->_key == prev->_key){
            l.Delete(prev->_key);
            prev = pos->_prev;
        }
        pos = pos->_next;
        prev = prev->_next;
    }
}

int main()
{
	List lst1, lst2, mergedList;
	
	cout<<"enter sorted values for the first list:"<< endl;
	cin>>lst1;
	cout<<"enter sorted values for the second list:"<< endl;
	cin>>lst2;

	mergedList = Merge(lst1,lst2);
	cout <<"the new merged list: " << mergedList <<endl;

	MakeSet(mergedList);
	cout<<"the new merged set: " << mergedList << endl;
	
	return 0;
}

