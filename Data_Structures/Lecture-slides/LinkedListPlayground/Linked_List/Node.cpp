#ifndef NODE_CPP
#define NODE_CPP

class Node {
    public:
        //constructor
        Node(int x){ //
            key = x;
            next = nullptr;
        }
    //private:
        int key;
        Node *next;
};

#endif