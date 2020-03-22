#ifndef LIST_CPP
#define LIST_CPP

#include "Node.cpp"
using namespace std;

class List {
    public:
        List(){head = nullptr;}
        Node* GetNode(int x);
        void Insert(Node x, Node y);
        void DeleteFirst();
        void InsertFirst(Node x);
        void Delete(int x);
        bool IsEmpty();
        int Length();
    private:
            Node* head; 
};


void List::Insert(Node x, Node y){ //insert node x after node y
    x.next = y.next;
    y.next = &x;
}

Node* List::GetNode(int x){
    Node *pos = head;
    if(pos->next == nullptr)
        return nullptr;
    while(pos->next->key != x){
        pos->next = pos->next->next
    }
    return pos->next;
}

void List::InsertFirst(Node x){
    head->next = &x;
}

void List::DeleteFirst(){
    if(head->next = nullptr) //ie, is empty
        return;
    head->next = head->next->next;
}


void List::Delete(int x){ //delete first encountered node with key x
    Node *pos = head;
    while(pos->next->key != x){
        if(pos->next == nullptr)
            return;
        pos = pos->next;
    }
    pos->next = pos->next->next;
}

bool List::IsEmpty(){
    if(head->next == nullptr)
        return true;
    else
        return false;
}

int List::Length(){
    int count = 0;
    Node *pos = head;
    while(pos->next == nullptr){
        pos->next = pos->next->next;
        count++;
    }
    return count;
}

#endif