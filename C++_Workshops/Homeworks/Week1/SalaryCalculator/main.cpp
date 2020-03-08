/* 
File Name: Salary Calculator
Description of program: Keep track of some employees, and output them
Course Name: C++ Workshops
Exercise# and Question#: 1, 2
Name: Eli Levin 341318228
Creation date: 03/03/20
Last Modification date: 07/03/20
*/
#include <iostream>
#include <cstring>
#include "employee.h"

using namespace std;

int main()
{ 
    int id;
    char name[81];
    float wage;
    int hours;
    int overtimeHours;

    //Keep track of some important employees
    Employee highestSalary;
    Employee mostHours;

    cout << "enter details, to end enter 0" << endl;
    
    while(true){
        cin >> id;
        if(!id){
            break;
        }
        cin >> name >> wage >> hours >> overtimeHours;
        if(wage < 0){
            cout << "ERROR" << endl;
            continue;
        }
        if(hours < 0){
            cout << "ERROR" << endl;
            continue;
        }
        if(overtimeHours < 0){
            cout << "ERROR" << endl;
            continue;
        }
        Employee currentEmployee(id, name, wage, hours, overtimeHours);
        
        //check if current employee has higher salary than the highest salary
        if(currentEmployee.CalcSalary() > highestSalary.CalcSalary()){
             highestSalary = currentEmployee;
        }

        //check if current employee has more hours than the most hours
        if(currentEmployee.GetTotalHours() > mostHours.GetTotalHours()){
            mostHours = currentEmployee;
        }
    }

    //print out the information
    cout << "highest salary: " << highestSalary.GetId() << " " << highestSalary.GetName() << endl;
    cout << "hardest worker: " << mostHours.GetId() << " " << mostHours.GetName() << endl;

    return 0;
}