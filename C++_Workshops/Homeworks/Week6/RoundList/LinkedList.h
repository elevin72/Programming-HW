#ifndef LIST_H
#define LIST_H

#include <iostream>
class linkedlist
{
protected:
    class Link
    {
    public:
        // constructor
        Link(int linkValue, Link* nextPtr);
        Link(const Link&);
        // data areas
        int value;
        Link* next;
    };	
public:
    // constructors
    linkedlist() : head(NULL) {}
  	linkedlist(const linkedlist& l);
   	~linkedlist();
    // operations
   	void add(int value); // adds a new element to the beginning of  the list
   	int firstElement() const; //returns the value of the first element of the list
   	bool isEmpty() const; 
   	void removeFirst(); // removes the first element of the list
   	void clear();
protected:    
   	Link* head;
 };

 #endif