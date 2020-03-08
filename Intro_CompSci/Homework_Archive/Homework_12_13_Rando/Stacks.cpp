#include <iostream>
using namespace std;

const int MAX_SIZE = 128;

void Push(int stack[], int& size, int val){

    if (stack[MAX_SIZE-1] == -1){
        cout << "Stack is full" << endl;
        return;
    }
    for (int i = size; i > 0; i--){
        stack[i] = stack[i-1];
    }
    stack[0] = val;
    size++;
}
int Pop(int stack[], int& size){
    int val = stack[0];
    for (int i = 0; i < size; i++){
        stack[i] = stack[i+1];
    }
    size--;
    return val;
}
int Peek(int stack[], int size){
    if(size == 0){
        cout << "Stack is empty!" << endl;
        return -1; 
    }
    else{
        return stack[0];
    }
}

void PrintStack(int stack[], int size){
    for (int i = 0; i < size; i++){
        cout << stack[i] << " ";
    }
    cout << "size is " << size << endl;
}

void Move(Tower *tower1, Tower *tower2){
    Push( tower2->stick , tower2->size, Pop(tower1->stick, tower1->size));
}

int main()
{ 

    int stack[MAX_SIZE] = {0};
    stack[0] = -1;
    int size = 0;

    int command;
    do
    {
        cout << "0=exit, 1=Push, 2=Pop, 3=Peek, 4=Print" << endl;
        cin >> command;
        switch (command)
        {
        case 0:
            cout << "Thank you and Goodnight" << endl;
            break;

        case 1: //Push
            {
            int x;
            cout << "Enter number to push to stack" << endl;
            cin >> x;
            Push(stack, size, x);
            cout << "size is " << size << endl;
            break; 
            }   

        case 2: //Pop
            {
            int y = Pop(stack, size);
            cout << y << " was popped from stack " << endl;
            cout << "size is " << size << endl;
            break;  
            }  

        case 3: //Peek
            Peek(stack, size);
            break;

        case 4: //Print
            PrintStack(stack, size);
            break;       
        
        default:
            break;
        }
        /* code */
    } while (command != 0);
    

    return 0;

}