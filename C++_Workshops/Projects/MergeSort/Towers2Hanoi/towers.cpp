#include <iostream>
using namespace std;

static int step = 0;

void SolveTowers(int rings, char src, char spare, char dest){
    if(rings == 0)
        return;
    SolveTowers(rings-1, src, dest, spare);
    cout << "Step " << ++step << ": Move ring " << rings << " from " << src << " to " << dest << endl;
    SolveTowers(rings-1, spare, src, dest);
}

int main (){
    int n;
    cout << "enter number of rings: " << endl;
    cin >> n;
    char src = 'a', spare = 'b', dest = 'c';
    SolveTowers(n, src, spare, dest);
    return 0;
}