#ifndef LIST_H
#define LIST_H

#include <iostream>

class List {
    friend std::ostream& operator<<(std::ostream& out, const List& l);
    friend std::istream& operator>>(std::istream& in, List& l);
    public:
        class Node {
            public:
            Node(int x){ 
                _key = x;
                _next = NULL;
                _prev = NULL;
            }
            int _key;
            Node* _next;
            Node* _prev;
        };
        Node* _head; 
        Node* _tail;
        List(){_head = NULL;}
        void Insert(int x);
        void Delete(int x);
        bool IsEmpty();
        int Length();
        List operator=(const List other);
    private:
        void InsertFirst(int x);
        void InsertLast(int x);
        void DeleteFirst();
        void DeleteLast();
        void Clear();

};

#endif