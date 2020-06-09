#ifndef MA_H
#define MA_H
#include "ba.h"


class MA : public BA {
  public:
    MA(int id, std::string firstName, std::string lastName, int numCourses, std::vector<int> _grades, bool doesResearch);
    ~MA(){}

    bool Milga();
    void Print();

    void SetDoesResearch(int doesResearch) {_doesResearch = doesResearch;}
    bool GetDoesResearch() {return _doesResearch;}
  protected:
    bool _doesResearch;
};


#endif