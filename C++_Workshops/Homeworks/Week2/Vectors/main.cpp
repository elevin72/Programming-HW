/* 
Program Name: Vectors
Description of program: Vector class
Course Name: C++ Workshops
Exercise# and Question#: Exercise 2 question 2
Name: Eli Levin 341318228
Creation date: 24/03/2020
Last Modification date: 24/03/20
*/
#include <iostream>
#include "vector.h"
using namespace std;

enum options
{
    stop, assignment, isEqual, mult, add, clear, delLast,
//   0         1         2      3     4     5       6
};
int main()
{
	Vector v1(10), v2(10), v3;
	for(int i=1;i<=4;i++)
	{
			v1.Insert(i);
			v2.Insert(i+4);
	}
	int choice;
	cout << "enter your choice 0-6\n";
	cin >> choice;
	while(choice){
		switch(choice){
		    case assignment: 
                v3.Assign(v1);
			    break;
            case isEqual:	
                if(v1.IsEqual(v2)){
                    cout << "v1==v2\n"; 
                } else {
                    cout << "v1!=v2\n";
                } 
			    break;
		    case mult:		
                cout << "v1*v2=" << v1.StrDotProduct(v2) << endl;
			    break;
		    case add:		
                v3.Assign(v1.StrNewCat(v2));
			    break;
		    case clear:		    
                v1.Clear();
			    break;
		    case delLast:	        
                v2.DelLast();
			    break;
		    default: 
                cout<<"ERROR";
		}

		v1.Print();
        v2.Print();		
        v3.Print();
		cout << "enter your choice 0-6\n";
		cin >> choice;
	}
	return 0;
}