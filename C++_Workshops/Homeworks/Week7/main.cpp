/* 
Program Name: Student derived classes
Description of program: Demonstrate polymorphism through example
Course Name: C++ Workshops
Exercise# and Question#: exercise 7
Name: Eli Levin 341318228
Creation date: 08/06/2020
Last Modification date: 08/06/2020
*/
#include <iostream>
#include <vector>
#include "student.h"
#include "ba.h"
#include "ma.h"
#include "phd.h"
using namespace std;

void printScholar(vector<Student*> arr){
  for(std::vector<Student*>::size_type i = 0; i < arr.size(); ++i){
    if(arr[i]->Milga()){
      arr[i]->Print();
    }
  }
}

int main()
{ 
  //initilize stupid &*#$^@ arrays for vectors in dumbest way possible because Moodle is 40 years old and it's compiler was written by Alan Turing himself.
  //Just want to say that the code ran fine on my computer when I just put:
  // vector<int>{...init list...} in a parameter corresponding to the vector
  //If there's a better way of doing this than what was done below that still works for c++1867, please send me an email and let me know
  int abesArr[3] = {90,100,90};
  vector<int> abesVec;
  for(int i = 0; i < 3; ++i){
    abesVec.push_back(abesArr[i]);
  }

  int yitzArr[10] = {100,100,90,100,90,100,90,100,90,100};
  vector<int> yitzVec;
  for(int i = 0; i < 10; ++i){
    yitzVec.push_back(yitzArr[i]);
  }

  int yaakovArr[7] = {90,100,90,100,90,100,90};
  vector<int> yaakovVec;
  for(int i = 0; i < 7; ++i){
    yaakovVec.push_back(yaakovArr[i]);
  }

  int saraArr[7] = {90,100,90,100,90,100,90};
  vector<int> saraVec;
  for(int i = 0; i < 7; ++i){
    saraVec.push_back(saraArr[i]);
  }

  /*
  FROM MOODLE:
  main.cpp:64:3: error: in C++98 ‘s 
  WHY C++98 ?? DO YOU KNOW WHAT YEAR IT IS???
  What is the better way to initialize vectors????
  */

  vector<Student*> students;
  students.push_back(new BA(123, "abe", "avrahamson", 3, abesVec));
  students.push_back(new BA(234, "yitzhak", "avrahamson", 10, yitzVec));
  students.push_back(new MA(345,"yaakov", "jacobson", 7, yaakovVec, false));
  students.push_back(new MA(456, "sara", "emanu", 7, saraVec, true));
  students.push_back(new PHD(567, "rivka", "imanu", 1, 30));
  students.push_back(new PHD(678, "rachel", "jacobs", 2, 20));
  students.push_back(new PHD(789, "leah", "jacobs", 2, 30));
 
  printScholar(students);
  
  return 0;

}