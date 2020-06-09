#ifndef ROUNDLIST_H
#define ROUNDLIST_H
#include "LinkedList.h"

class RoundList: public linkedlist {
    public:
        RoundList();
        RoundList(const RoundList& l);
        void addToEnd(int val);
        int search(int n) const;
        void clear();
        void add(int val);
        void removeFirst();
};

#endif