#include <iostream>
using namespace std;

const int MAX_SIZE = 64;

struct Tower 
{
    int stick[MAX_SIZE];
    int size;
    char name;
};

struct TowerOfHanoi
{
    Tower *A;
    Tower *B;
    Tower *C;
};

void Push(int stack[], int& size, int val);
int Pop(int stack[], int& size);
void Move(Tower *tower1, Tower *tower2);
Tower* SolveTower(int n, Tower* home, Tower* avail, Tower* dest); //returns address of tower moved from
void InitializeTowers(TowerOfHanoi* T, int n);
void DeleteTowers(TowerOfHanoi* T);
   
int main()
{ 
    int n;
    cout << "********" << endl
    << "Enter how many rings are on your tower:  ";
    cin >> n;
    cout << endl << "*******"  << endl;

    TowerOfHanoi *T = new TowerOfHanoi;
    InitializeTowers(T, n);

    SolveTower(n,T->A, T->B, T->C);
    
    DeleteTowers(T);
    return 0;
}

Tower* SolveTower(int n, Tower* home, Tower* avail, Tower* dest){
    Tower *subTower;
    if(n != 1){
        subTower = SolveTower(n-1, home, dest, avail); //solve the n-1 tower to the "wrong" spot. Notice that avail and dest are switched in this call. subTower is where the (n-1)th size tower is placed.
    }
    Move(home, dest); //move n from home to destination
    if(n == 1){
        return dest; //return pointer to tower where 1 was moved to, i.e., remember where the smaller, sub-solution was saved. Once we return back to the calling function, we will move nth-ring of calling function to correct position(with the Move() on line 49) then want to solve the smaller subTower to correct position on top of nth-ring
    } 
    return SolveTower(n-1, subTower, home, dest); //once the (n-1)th subTower has been placed in "wrong" spot (on line 47), solve that tower from its location (subTower) to its destination. In this call, 'home' is the tower that we're not touching, since nth ring was already moved from there.
} 

void Push(int stack[], int& size, int val){
    if (size == MAX_SIZE-1){
        cout << "Stack is full" << endl;
        return;
    }
    for (int i = size; i > 0; i--){
        stack[i] = stack[i-1];
    }
    ++size;
    stack[0] = val;
}

int Pop(int stack[], int& size){
    int val = stack[0];
    for (int i = 0; i < size; i++){
        stack[i] = stack[i+1];
    }
    size--;
    return val;
}

void Move(Tower *tower1, Tower *tower2){
    int ringSize = Pop(tower1->stick, tower1->size);
    Push( tower2->stick , tower2->size, ringSize);
    static int count = 0;
    cout << "Step " << ++count << ": "
    << "Move ring " << ringSize << " from Tower " << tower1->name 
    << " to Tower " << tower2->name << endl;
}

void InitializeTowers(TowerOfHanoi* T, int n){
    T->A = new Tower;
    T->B = new Tower;
    T->C = new Tower;
    T->A->name = 'A';
    T->B->name = 'B';
    T->C->name = 'C';
    T->A->size = 0;
    T->B->size = 0;
    T->C->size = 0;
    for (int i = n; i > 0; --i){
        Push(T->A->stick, T->A->size, i);
    }
}

void DeleteTowers(TowerOfHanoi* T){
    delete[] T->A;
    delete[] T->B;
    delete[] T->C;
    delete T;
}



