#ifndef PHD_H
#define PHD_H
#include "student.h"

class PHD : public Student {
  public:
    PHD(int id, std::string firstName, std::string lastName, int numCourses, int researchHours);
    ~PHD(){}

    void SetResearchHours(int researchHours){ _researchHours = researchHours;}
    int GetResearchHours(){return _researchHours;}
    bool Milga();
    void Print();

  private:
    int _researchHours;

};


#endif