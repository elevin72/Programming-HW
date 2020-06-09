#ifndef STUDENT_H
#define STUDENT_H
#include <string>

class Student{ 
  public:
    //no default ctor: not issue if calling different ctor in init list in derived classes
    Student(int id, std::string firstName, std::string lastName, int numCourses);
    virtual ~Student(){}
    virtual bool Milga() = 0;
    virtual void Print() = 0;

    void SetID(int id){_id = id;}
    void SetFirstName(std::string firstName){_firstName = firstName;}
    void SetLastName(std::string lastName){_lastName = lastName;}
    void SetnCourses(int nCourses){_numCourses = nCourses;}

    int GetID() const {return _id;}
    std::string GetFirstName() const {return _firstName;}
    std::string GetLastName() const {return _lastName;}
    int GetnCourses() const {return _numCourses;}
  
  protected:
    int _id;
    std::string _firstName;
    std::string _lastName;
    int _numCourses;
};


#endif