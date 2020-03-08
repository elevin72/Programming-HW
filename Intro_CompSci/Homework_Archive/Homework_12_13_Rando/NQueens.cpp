/* 
File Name: HW13_5.cpp
Description of program: Solve N Queens problem
Course Name: Introduction to Computer Science
Exercise# and Question#: 13, 5
Name: Eli Levin 341318228
Creation date: 30-1-20
Last Modification date: 5-2-20
*/
#include <iostream>
using namespace std;

//this function recieves a chess board matrix, and a specific spot on the board. It also recieves the size of the matrix as n. We want it to tell us if that spot is legal or not
bool isLegal(int **board, int n, int R, int C){ 
    //only columnn number is changing
    //check horizontal
    int sum = 0;
    for (int i = 0; i < C; i++){
        sum += board[R][i];
    }
    if(sum){
        return false;
    }

    //check diagonal going up to the left
    sum = 0;
    for (int i = R, j = C; i >= 0 && j >= 0; i--, j--){
        sum += board[i][j];
    }
    if(sum){
        return false;
    }
    
    //check diagonal going down to the left
    sum = 0;
    for (int i = R, j = C; i >= 0 && j >= 0 && i < n; i++, j--){
        sum += board[i][j];
    }
    if(sum){
        return false;
    }

    return true;
}


void PrintBoard(int **board, int n){
    for (int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << (board[i][j]? "Q " : "- ");
        } 
        cout << endl;
    }
    for (int i = 0; i < n; i++){
        cout << "* ";
    }
    cout << endl;
}

//R represents our current row number we're operating on, n represents how many queens left to place
//C will represent the current column that we're trying to solve
bool PlaceQueens(int **board, int n, int C){ //always start from column 0
    if(C == n){ //if the current column that we're solving is equal to # of queens we have i.e., we've solved for all the queens
        return true;
    }
    for (int i = 0; i < n; i++){ //loop through all columns
        if(isLegal(board, n, i, C)){ //first check if given spot is legal based on previous queens
            board[i][C] = 1; // if spot is legal, make it a queen
            if(PlaceQueens(board, n, C+1)){ // if you are then able to place all the subsequent queens on the board as well, return true
                return true;
            }
            board[i][C] = 0; //if you cannot undo that queen that you tried and continue looping
        }
    }
    return false; //if we could not manage to place all queens then return false
}



int main()
{   
    int n; 
    cout << "enter n" << endl;
    cin >> n;
    int **board = new int*[n];
    for (int i = 0; i < n; i++){
        board[i] = new int[n];
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            board[i][j] = 0;
        }
    }
    
    PlaceQueens(board, n, 0);
    PrintBoard(board, n);
    

    return 0;

}