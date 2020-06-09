#ifndef STRING_CPP
#define STRING_CPP

#include <iostream>
#include "string.h"
#include <cstring>
using namespace std;

//constructors
String::String() : String("") {}

String::String(const char* str) {
	setString(str);
}

String::String(const String& str) : String(str._array){}

String::~String(){
	delete[] _array;
}

//operators from notebook
String& String::operator=(const String& str){
	if (&str != this) {
		delete[] _array;
		setString(str._array);
	}
	return *this;
}

String String::operator+(const String& str){
	int length = _len + str._len + 1;
	char* p = new char[length];
	strncpy(p, _array, _len);
	strncat(p, str._array, str._len);

	String tmp(p);
	delete[] p;

	return tmp;
}

char& String::operator[](int index){
	if (index < 0 || index > _len); // throw exception
	return _array[index];
}

bool String::operator==(const String& str) const {
	return strcmp(_array, str._array) == 0;
}

String String::substr(int start, int end){
	if (start < 0 || end > _len || start > end); // throw exception

	int len = end - start + 2;
	char* p = new char[len];
    strncpy(p, &_array[start], len);
	String tmp(p);
	delete[] p;
	return tmp;
}

// setString: does a deep copy
void String::setString(const char* str){
	// needed since strlen no longer checks for null
	if (str == NULL)
		str = "";

	_len = strlen(str);
	_array = new char[_len + 1];
    strncpy(_array, str, _len + 1);
}

void String::print(){
	cout << _array << endl;
}

bool String::operator<(const String& other) const {
    if(this->StringCompare(other) == -1){
        return true;
    }
    return false;
}

bool String::operator>(const String& other) const {
    if(this->StringCompare(other) == 1){
        return true;
    }
    return false;
}

bool String::operator<=(const String& other) const {
    if(this->StringCompare(other) == -1 || this->StringCompare(other) == 0){
        return true;
    }
    return false;
}

bool String::operator>=(const String& other) const {
    if(this->StringCompare(other) == 1 || this->StringCompare(other) == 0){
        return true;
    }
    return false;
}

bool String::operator!=(const String& other) const {
    if(this->StringCompare(other) != 0){
        return true;
    }
    return false;
}

String& String::insert(int index, const String& str){
    if(index > str._len){
        cout << "ERROR" << endl;
        return *this;
    }
	int length = _len + str._len + 1;
    char* a = new char[length];
    strncpy(a, str._array, index);
    strncat(a, _array, _len);
    strncat(a, &str._array[index], str._len - index);
    delete[] _array;
    _array = a;
    print();
    return *this;
}

int String::StringCompare(const String& other) const {
    int smallerLen = this->_len < other._len ? other._len : this->_len; 
    for (int i = 0; i < smallerLen; ++i){
        if(this->_array[i] > other._array[i]){
            return 1;
        }
        if(this->_array[i] < other._array[i]){
            return -1;
        }
    }
    if(this->_len > other._len){
        return 1;
    }
    if(this->_len < other._len){
        return -1;
    }
    return 0;

    
}

#endif
