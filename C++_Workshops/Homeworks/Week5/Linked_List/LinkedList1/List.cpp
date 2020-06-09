#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"
#include <iostream>
using namespace std;

void List::Insert(int x){
    Node *pos = _head;
    while(pos != NULL && pos->_key <= x){
        pos = pos->_next; 
    }
    if(pos == _head){
        InsertFirst(x);
        return;
    }
    if(pos == NULL){
        InsertLast(x);
        return;
    }
    Node* n = new Node(x);
    n->_next = pos;
    n->_prev = pos->_prev;
    pos->_prev->_next = n;
    pos->_prev = n;
}

void List::InsertFirst(int x){
    Node* n = new Node(x);
    if(IsEmpty()){
        _tail = _head = n;
        return;
    }
    n->_next = _head;
    _head->_prev = n;
    _head = n;
}

void List::InsertLast(int x){
    Node* n = new Node(x);
    if(IsEmpty()){
        _tail = _head = n;
        return;
    }
    n->_prev = _tail;
    _tail->_next = n;
    _tail = n;

}

void List::DeleteFirst(){
    if(IsEmpty()) //ie, is empty
        return;
    Node* tmp = _head->_next;
    delete _head;
    _head = tmp;    
}

void List::DeleteLast(){
    if(IsEmpty()) //ie, is empty
        return;
    Node* tmp = _tail->_prev;
    delete _tail;
    tmp->_next = NULL;
    _tail = tmp;
    
}


void List::Delete(int x){ //delete first encountered node with key x
    Node *pos = _head;
    while(pos->_key != x){
        if(pos == NULL){
            throw ("value not found");
            return;
        }
        pos = pos->_next;
    }
    if(pos == _head){
        DeleteFirst();
        return;
    }
    if(pos == _tail){
        DeleteLast();
        return;
    }
    pos->_prev->_next = pos->_next;
    pos->_next->_prev = pos->_prev;
    delete pos;
}

void List::Clear(){
    Node* pos = _head;
    while(pos != NULL){
        delete pos;
        pos = pos->_next;
    }
    _head = _tail = NULL;
}

bool List::IsEmpty(){
    if(_head == NULL)
        return true;
    else
        return false;
}

int List::Length(){
    int count = 0;
    Node *pos = _head;
    while(pos != NULL){
        pos= pos->_next;
        count++;
    }
    return count;
}

//operators
List List::operator=(const List other){ 
    Clear();
    Node* pos = other._head;
    while(pos != NULL){
        Insert(pos->_key);
        pos = pos->_next;
    }
    return *this;
}



istream& operator>>(istream& in, List& l){
    int x;
    in >> x;
    l.InsertLast(x);
    while(true){
        in >> x;
        if(x <= l._tail->_key){
            break;
        }
        l.InsertLast(x);
    }
    return in;
}

ostream& operator<<(ostream& out, const List& l){
    List::Node* p = l._head;
    while(p != NULL){
        out << p->_key << " ";
        p = p->_next;
    }
    return out;
}

#endif