/* 
File Name: HW5_3.cpp
Description of program: Produce checksum on any 8 digit number
Course Name: Introduction to Computer Science
Exercise# and Question#: 5.3
Name: Eli Levin 341318228
Creation date: 3-12-19
Last Modification date: 3-12-19
*/
#include <iostream>
using namespace std;

int SumOfDigits(int);
int Find_Checksum(int id);

int main()
{ 

    int userInput;
    cout << "enter your ID:" << endl;
    cin >> userInput;
    while(userInput < 0)
    {
        cout << "ERROR" << endl;
        cin >> userInput;
    }
    cout << "your full ID is:" << endl << userInput <<
     Find_Checksum(userInput) << endl;
    return 0;

}

int SumOfDigits(int num)
{
    int sum = 0;
    while(num >= 0)
    {
        sum += num % 10;
        num /= 10;
        if (num == 0)
        {
            return sum;
        }  
    }     
}

int Find_Checksum(int id)
{
    int weight = 2; //initializing weight to 2 since weight of final digit in id is 2
    int placeValue;
    int sum = 0;
    for(int i = 0; i < 8; i++)
    {   
        if (weight == 2)
        {

            placeValue = weight * (id % 10); //step c -- 'Multiply each digit of the id by its weight'
            id /= 10; // make id ready for next loop
            placeValue = SumOfDigits(placeValue); //step d -- 'Replace all 2 digit numbers computed in step c with their sum'
            sum += placeValue; // step e -- 'sum up all the digits computed in step d'
            weight = 1; //set weight = 1 for next loop
        }
        else //weight == 1;
        {
            
            placeValue = weight * (id % 10);
            id /= 10;
            placeValue = SumOfDigits(placeValue);
            sum += placeValue;
            weight = 2; //set weight = 2 for next loop
        }
    }
    int checkSum = 10 - (sum % 10);

    return checkSum;
}