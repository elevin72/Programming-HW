#include <iostream>
using namespace std;

int main()
{ 
    int n = 0;
    cout << "enter a number:" << endl;
    cin >> n;
    while(n < 1)
    {
        cout << "ERROR" << endl;
        cin >> n;
    }
    bool descending = true;
    while (true)
    {
        int var1 = n % 10; 
        int var2 = (n / 10) % 10;
        n /= 10; 
        if (n == 0) 
            break; 
        if (var2 != var1 + 1)
        {
            descending = false;
            break;
        }
    }
    if (descending == true)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;  
    return 0;
}

