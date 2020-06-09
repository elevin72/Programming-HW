#include <iostream>
#include <queue>
#include <ctime>
using namespace std;
int _SIZE_ = 10;

void enqueue(queue<int> &q, int x){
    q.push(x);
}
int dequeue(queue<int> &q){
    int x = q.front();
    q.pop();
    return x;
}

void printQueue(queue<int> &q){
    cout << "<- "; 
    int size = q.size();
    for(int i = 0; i < size; ++i){
        int x = dequeue(q);
        cout << x << " ";
        enqueue(q, x);
    }
    cout << "<-" << endl;
}


int main(){

    srand(time(nullptr));
    queue<int> Q1, Q2;
    for(int i = 0; i < _SIZE_; ++i){
        enqueue(Q1, rand() % 20 + 1);
        enqueue(Q2, rand() % 20 + 1);
    }
    cout << "Q1: "; 
    printQueue(Q1);
    cout << "Q2: ";
    printQueue(Q2); 



    int Q2_size = Q2.size();
    for(int i = 0; i < Q2_size; ++i){
        int canidate = dequeue(Q2);
        for(int j = 0; j < Q1.size(); ++j){
            int p = dequeue(Q1);
            if(p == canidate){
                --j;
            } else {
                enqueue(Q1, p);
            }
        }
    }

    cout << "Q1: "; 
    printQueue(Q1);
    cout << "Q2: ";
    printQueue(Q2);

    return 0;
}