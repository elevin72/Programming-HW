#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{  
public:
    Employee();
    Employee(int, char*, float, int, int);
    float CalcSalary();
    void SetId(int);
    void SetName(char*);
    void SetWage(float);
    void SetHours(int);
    void SetOvertimeHours(int);
    int GetId();
    char* GetName();
    float GetWage();
    int GetRegularHours();
    int GetOvertimeHours();
    int GetTotalHours();
    
private:
    int _id;
    char _name[81];
    float _wage;
    int _hours;
    int _overtimeHours;
};

#endif