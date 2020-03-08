#include <iostream>
using namespace std;

void PrintStars(int n){
    if(n==0){   
        return;
    }
    cout << "*";
    PrintStars(n-1);
}

void PrintTriangle(int n){
    if(n == 0){
        return;
    }
    PrintTriangle(n-1);
    PrintStars(n);
    cout << endl;
}

void Loops3(int n)
{
	cout << n << endl;

	if (n == 0)
		return;

	Loops3(n - 1);
}

int main()
{ 
    int n;
    cout << "enter n" << endl;
    cin >> n;
    Loops3(n);


    return 0;

}