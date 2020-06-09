#ifndef BA_CPP
#define BA_CPP
#include "ba.h"
#include <vector>
using namespace std;

BA::BA(int id, string firstName, string lastName, int numCourses, vector<int> grades)
: Student(id, firstName, lastName, numCourses) {
  _grades = grades;
}

float BA::Average(){
  int sum = 0;
  for(vector<int>::size_type i = 0; i < _grades.size(); ++i){
    sum+= _grades[i];
  }
  return (float)sum/_grades.size();
}

bool BA::Milga(){
  return _numCourses >= 10 && Average() > 95;
}

void BA::Print(){
  cout << "ID: " << _id << "\n";
  cout << "first name: " << _firstName << "\n";
  cout << "last name: " << _lastName << "\n";
  cout << "num courses: " << _numCourses << "\n";
  cout << "grades: ";
  for(vector<int>::size_type i = 0; i < _grades.size(); ++i){
    cout << _grades[i] << " ";
  }
  cout << "\n";
}

#endif