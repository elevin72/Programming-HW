#ifndef STUDENT_CPP
#define STUDENT_CPP
#include "student.h"
using namespace std;

Student::Student(int id, string firstName, string lastName, int numCourses){
  _id = id;
  _firstName = firstName;
  _lastName = lastName;
  _numCourses = numCourses;
}

#endif