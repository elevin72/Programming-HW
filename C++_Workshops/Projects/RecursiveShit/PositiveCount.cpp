#include <iostream>
using namespace std;
const int SIZE = 10;

bool isPositive(int x){
    return x>0;
}
	
int PositiveCount(int *A, int n) {
    if(n == 0){
        return 0;
    } 
	if(isPositive(A[n-1])){
        return 1 + PositiveCount(A, n-1);
    } 
	return PositiveCount(A, n-1);
}

int divide(int p, int q){
    if(p < q){
        return 0;
    }
    return 1 + divide(p-q, q);
}

int modulo(int p, int q){
    if(p < q){
        return p;
    }
    if(p-q >= q){
        return modulo(p-q, q);
    }
    return p-q;
}

int main(){

    //int A[SIZE] = {1,1,0,-1,1,0,1,0,-1,1};
    int p = 15, q = 7;
    cout << modulo(p,q) << " = " << p%q << endl;

    return 0;
}