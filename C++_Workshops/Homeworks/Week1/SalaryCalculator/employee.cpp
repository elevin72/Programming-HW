#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP

#include "employee.h"
#include <iostream>
#include <cstring>
using namespace std;

//Employee default constructor
Employee::Employee(){
    _id = 0;
    _name[0] = '\0';
    _wage = 0;
    _hours = 0;
    _overtimeHours = 0;
}

//Employee non-default constructor
Employee::Employee(int id, char* name, float wage, int hours, int overtimeHours){
    _id = id;
    strcpy(_name, name);
    _wage = wage;
    _hours = hours;
    _overtimeHours = overtimeHours;
}


//Calculate salary
float Employee::CalcSalary(){
    return (float)(_hours*_wage)+(_overtimeHours*1.5*_wage);
}

//All the setters
void Employee::SetId(int id){
    _id = id;
}
void Employee::SetName(char* name){
    strcpy(_name, name);
}
void Employee::SetWage(float wage){
    _wage = wage;
}
void Employee::SetHours(int hours){
    _hours = hours;
}
void Employee::SetOvertimeHours(int overtimeHours){
    _overtimeHours = overtimeHours;

}

//All the Getters
int Employee::GetId(){
    return _id;
}
char* Employee::GetName(){
    return _name;
}
float Employee::GetWage(){
    return _wage;
}
int Employee::GetRegularHours(){
    return _hours;
}
int Employee::GetOvertimeHours(){
    return _overtimeHours;
}
int Employee::GetTotalHours(){
    return _hours + _overtimeHours;
}

#endif

