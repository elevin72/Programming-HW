#ifndef ROUNDLIST_CPP
#define ROUNDLIST_CPP
#include "RoundList.h"

RoundList::RoundList(){
    head = NULL;
}

RoundList::RoundList(const RoundList& l){
    Link* p = l.head;
    if(l.isEmpty()){
        head = NULL;
        return;
    }
    while(p->next != l.head){
        addToEnd(p->value);
        p = p->next;
    }
}

void RoundList::addToEnd(int val){
    Link* l = new Link(val, head);
    if(this->isEmpty()){
        head = l;
        head->next = head;
    } else {
        Link* p = head;
        while(p->next != head){
            p = p->next;
        }
        p->next = l;
        l->next = head;
    }
}

int RoundList::search(int n) const {
    if(this->isEmpty()){
        return -1;
    }
    Link* p = head;
    for(int i = 0; i < n; ++i){
        p = p->next;
    }
    return p->value;
}

void RoundList::add(int val){ 
    Link* l = new Link(val, head);
    if(this->isEmpty()){
        head = l;
        head->next = head;
    } else {
        Link* p = head;
        while(p->next != head){
            p = p->next;
        }
        l->next = head;
        head = p->next = l;
    }
}

void RoundList::removeFirst(){
    if(this->isEmpty()){
        return;
    }
    Link* p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = head->next;
    p = head;
    head = head->next;
    if(p == head){
        head = NULL;
    }
    delete p;
}

void RoundList::clear(){
    Link* next;
    for (Link* p = head; p->next != head; p = next)
    {
        // delete the element pointed to by p
        next = p->next;
        p->next = NULL;
        delete p;
    }
    head = NULL;
    delete head;
}



#endif