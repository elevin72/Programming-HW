#include "LinkedList.h"	
linkedlist::Link::Link(int val, Link * nxt) : value(val), next(nxt) {}
linkedlist::Link::Link(const Link & source) : value(source.value), next(source.next) {}
linkedlist::linkedlist(const linkedlist & l)
{
   	Link * src, * trg;
   	if (l.head == NULL)
       	head = NULL;
   	else
    {
       	head = new Link((l.head)->value, NULL);
       	src = l.head;
       	trg = head;
       	while (src->next != NULL)
        {
           	trg->next = new Link
               	((src->next)->value, NULL);
           	src = src->next;
         	trg = trg->next;
       	}
   	}
}
linkedlist::~linkedlist()
{
    clear();
}
void linkedlist::clear()
{
    	// empty all elements from the List
   Link * next;
   for (Link* p = head; p != NULL; p = next)
   {
        // delete the element pointed to by p
       	next = p->next;
       	p->next = NULL;
    	delete p;
   }
    	// mark that the List contains no elements
   head = NULL;
}
bool linkedlist::isEmpty() const
{       
   return head == NULL;
}
void linkedlist::add(int val)
{
    //Add a new value to the front of a Linked List
   	head = new Link(val, head);
    if (head == NULL)
       throw "failed in memory allocation";
}
int linkedlist::firstElement() const
{
    if (isEmpty())
        throw "the List is empty, no first Element";
    return head->value;
 }
void linkedlist::removeFirst()
{
   	// make sure there is a first element
   	if (isEmpty())
       	throw "the List is empty, no Elements to remove";
   	// save pointer to the removed node
   	Link * p = head;
   	// reassign the first node
   	head = p->next;
   	p->next = NULL;
   	// recover memory used by the first element
   	delete p;
}