#include <iostream>
using namespace std;
int main() { 
    int x,n;
    cout << "enter 2 numbers:" << endl;
    cin >> x >> n;
    while(n<1) {
        cout << "ERROR" << endl;
        cin >> n;
    }
    float sum=0;
    int numerator = 1;
    int denominator = 1;  
    int result; 
    for (int i = 0; i < n ; i++) { 
        result = 1;
        for (int j = 0; j < denominator; j++){
            result *= x;
        }
        sum += ((float)numerator/denominator)*result; 
        numerator *= -1;
        denominator += 2; 
    }
    cout << sum << endl;
    return 0;
}


