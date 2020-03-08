/* 
File Name: HW2_8.cpp
Description of program: calculate landing time when given takeoff and flight duration
Course Name: Introduction to Computer Science
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date: 11-11-19
Last Modification date: 11-11-19
*/
#include <iostream>
using namespace std;

int main()
{ 
    //declare variables
    int takeoffHour, takeoffMinute, takeoffSecond;
    //get takeoff time from user and put into your variables
    cout << "enter flight takeoff:" << endl;
    cin >> takeoffHour;
    cin >> takeoffMinute;
    cin >> takeoffSecond;

    //declare some more variables
    int durationHour, durationMinute, durationSecond;
    //get duration time from user and put into your variables
    cout << "enter flight duration:" << endl;
    cin >> durationHour;
    cin >> durationMinute;
    cin >> durationSecond;

    //calculate the number of seconds in the landing time
    int totalSecond = takeoffSecond + durationSecond;
    int landingSecond = totalSecond % 60;
    
    //calculate the number of minutes in the landing time, including the extra minute 
    //if there were more than 59 seconds
    int totalMinute = takeoffMinute + durationMinute + (totalSecond/60);
    int landingMinute = totalMinute % 60;

    //calculate the number of hours in the landing time, including extra hour if more than 59 minutes
    int landingHour = (takeoffHour + durationHour + (totalMinute/60)) % 24;
    //no need to create a total hours here, because I don't care how many times we loop through the day, as long as I print the correct time.

    cout << "flight arrival is: " << endl << landingHour << ":" << landingMinute << ":" << landingSecond << endl;

    return 0;

}

/*
eli@eli-ThinkPad-S2:~/Desktop/Intro_CompSci/Homework$ ./hw2_8
enter flight takeoff:
3
24
56
enter flight duration:
14
13
17
flight arrival is: 
17:38:13
*/
