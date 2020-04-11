#ifndef VECTOR_CPP
#define VECTOR_CPP

#include <iostream>
#include "vector.h"
using namespace std;

//default constructor
Vector::Vector(){
    _capacity = 10;
    _size = 0;
    _data = new int[10];
}

//non-default constructor
Vector::Vector(int capacity){
    _capacity = capacity;
    _size = 0;   //can this be in init list?
    _data = new int[capacity];
}

//copy constructor
Vector::Vector(const Vector& v){
    _capacity = v._capacity;
    _size = v._size;
    _data = new int[_capacity];
    for(int i = 0; i < _size; ++i){
        _data[i] = v._data[i];

    }
}

Vector::~Vector(){
    delete[] _data;
}

int Vector::GetCapacity(){
    return _capacity;
}

int Vector::GetSize(){
    return _size;
}

void Vector::Print(){
    cout << "capacity: " << _capacity << " size: " << _size << " val: ";
    for(int i = 0; i < _size; ++i){
        cout << _data[i] << " ";
    }
    cout << endl;
}

void Vector::Assign(const Vector v){
    _capacity = v._capacity;
    _size = v._size;
    delete[] _data; //maybe must be set to nullptr
    _data = new int[_capacity];
    for(int i = 0; i < _size; ++i){
        _data[i] = v._data[i];
    }
}

bool Vector::IsEqual(Vector v){
    if(_size != v._size){
        return false;
    }
    for(int i = 0; i < _size; ++i){
        if(_data[i] != v._data[i]){
            return false;
        }
    }
    return true;
}

int& Vector::At(int index){
    if(index >= _capacity){
        cout << "ERROR" << endl;
        return index;
    }
    return _data[index];
}

int Vector::StrDotProduct(const Vector v){
    if(_size != v._size){
        cout << "ERROR" << endl;
        return -1;
    }
    int sum = 0;
    for(int i = 0; i < _size; ++i){
        sum += _data[i] * v._data[i];
    }
    return sum;
}

Vector Vector::StrNewCat(const Vector& v){
    int newSize= _size + v._size;
	Vector newVec;
	newVec._capacity = newSize;

	newVec._size = newSize;

	newVec._data = new int[newSize];

	int i;

	for (i = 0; i < _size; i++)
		newVec._data[i] = _data[i];
	for(int j=0;j<v._size;i++,j++)
		newVec._data[i] = v._data[j];

	return newVec;


    /*
	Vector newVec(_capacity + v._capacity);
	newVec._size = _size + v._size;
	newVec._data = new int[newVec._size];
    int i;
	for (i = 0; i < _size; i++){
        newVec._data[i] = _data[i];
    }	
	for(int j=0; j < v._size; i++,j++){
        newVec._data[i] = v._data[j];
    }
	return newVec;
    */
}

void Vector::Clear(){
    for(int i = 0; i < _size; ++i){
        _data[i] = 0;
    }
    _size = 0;
}

void Vector::DelLast(){
    if(!_size){
        cout << "ERROR" << endl;
        return;
    }
    _data[--_size] = 0;
}

void Vector::Insert(int val){
    if(_size >= _capacity){
        cout << "ERROR";
        return;
    }
    _data[_size++] = val;

}

#endif