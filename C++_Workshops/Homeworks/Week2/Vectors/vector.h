#ifndef VECTOR_H
#define VECTOR_H

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
    int GetSize();
    void Print();
    void Assign(Vector v);
    bool IsEqual(Vector v);
    int 
};

Vector::Vector(/* args */)
{
}

Vector::~Vector()
{
}




#endif