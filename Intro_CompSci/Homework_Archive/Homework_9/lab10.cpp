
#include <iostream>
using namespace std;

int main()
{ 

    return 0;

}


int **RightTriangle(int lines){
    srand(0);

    int **triangle = new int*[lines];
    for (int i = 0; i < count; i++){
        *triangle = new int[i+1];
        for (int j = 0; j<i+1; j++){
            triangle[i][j] = rand()%900+100;        } 
    }
    return triangle;
    
}

void DeleteTriangle(int **triangle, int n){
    for (int i = 0; i < n, i++){
        delete[] triangle
    }
}