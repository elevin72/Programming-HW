#ifndef PHD_CPP
#define PHD_CPP
#include "phd.h"
#include <iostream>
using namespace std;

PHD::PHD(int id, string firstName, string lastName, int numCourses, int researchHours)
  : Student(id, firstName, lastName, numCourses) {
    _researchHours = researchHours;
}

bool PHD::Milga(){
  return _numCourses >= 2 && _researchHours > 25;
}

void PHD::Print(){
  cout << "ID: " << _id << "\n";
  cout << "first name: " << _firstName << "\n";
  cout << "last name: " << _lastName << "\n";
  cout << "num courses: " << _numCourses << "\n";
  cout << "hours: " <<  _researchHours << "\n";
}

#endif