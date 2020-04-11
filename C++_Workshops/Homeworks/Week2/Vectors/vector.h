#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
private:
    int* _data;
    int _capacity;
    int _size;
public:
    Vector();
    Vector(int capacity);
    Vector(const Vector& v);
    ~Vector();

    int GetCapacity();
    int GetSize();

    void Print();
    void Assign(Vector v);
    bool IsEqual(Vector v);
    int& At(int index);
    int StrDotProduct(Vector v);   //instead of strcatcat
    Vector StrNewCat(const Vector& v);
    void Clear();
    void DelLast();
    void Insert(int val);
};

#endif