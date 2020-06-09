#ifndef MA_CPP
#define MA_CPP
#include "ma.h"
using namespace std;

MA::MA(int id, string firstName, string lastName, int numCourses, vector<int> _grades, bool doesResearch)
  : BA(id, firstName, lastName, numCourses, _grades) {
    _doesResearch = doesResearch;
  }

bool MA::Milga(){
  return _numCourses >= 7 && Average() > 90 && _doesResearch;
}

void MA::Print(){
  cout << "ID: " << _id << "\n";
  cout << "first name: " << _firstName << "\n";
  cout << "last name: " << _lastName << "\n";
  cout << "num courses: " << _numCourses << "\n";
  cout << "grades: ";
  for(vector<int>::size_type i = 0; i < _grades.size(); ++i){
    cout << _grades[i] << " ";
  }
  cout << "\n";
  cout << "research: " << (_doesResearch ? "yes" : "no") << "\n";
}

#endif