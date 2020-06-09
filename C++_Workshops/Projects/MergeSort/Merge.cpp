#include <iostream>
#include <ctime>
using namespace std;

const int NUM = 10000000; 


void merge(int *A, int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int *L, *R;
    L = new int[n1];
    for(int i = 0; i < n1; i++){
        L[i] = A[p+i]; 
    }
    R = new int[n2]; 
    for(int i = 0; i < n2; i++){
        R[i] = A[q+i+1]; 
    }
    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            A[k++] = L[i++];
        }
        else {
            A[k++] = R[j++];
        }
    }
    while(i < n1){
        A[k++] = L[i++];
    }
    while(j < n2){
        A[k++] = R[j++];
    }

}

void mergeSort(int* A, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}


int main()
{ 
    srand(time(nullptr));
    int A[NUM];
    for(int i = 0; i < NUM; i++){
        A[i] = rand()%NUM + 1;
    }
    cout << endl;
    for(int i = 0; i < NUM; i++){
        cout << A[i] << " ";
    }
    cout << endl << "**********MERGE**************" << endl;
    mergeSort(A, 0, NUM-1);
    for(int i = 0; i < NUM; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;

}

/*

int A[1000];
    for(int i = 0; i < 1000; i++){
        A[i] = rand()%1000 + 1;
    }
    for(int i = 0; i < 1000; i++){
        cout << A[1] << " ";
    }
    cout << endl << "**********MERGE**************" << endl;
    mergeSort(A, 1, 1000);
    for(int i = 0; i < 1000; i++){
        cout << A[1] << " ";
    }

    return 0;


*/