#ifndef BA_H
#define BA_H
#include <vector>
#include <iostream>
#include "student.h"

class BA : public Student {
  public:
    //probably same issue with default ctor
    BA(int id, std::string firstName, std::string lastName, int numCourses, std::vector<int> _grades);
    ~BA(){}
    bool Milga();
    void Print();

    void SetGrades(int num, int* grades);
    std::vector<int> GetGrades() const {return _grades;}
    float Average();

  protected:
    std::vector<int> _grades;
};


#endif