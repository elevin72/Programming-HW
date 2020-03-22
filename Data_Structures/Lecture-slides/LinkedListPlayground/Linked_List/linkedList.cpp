//this file is meant to be a sandbox/playground for linked lists and how to use them and all their syntax, because as of 19.3.20 I DONT GET IT
#include "List.cpp"
#include <iostream>
using namespace std;

int main()
{ 
    cout << "Welcome to the Linked List Playground! You have several options what to do." << endl;
    cout << "0 -- Exit" << endl;
    //cout << "1 -- Create New List" << endl;
    cout << "1 -- Insert First" << endl;
    cout << "2 -- Delete First" << endl;
    cout << "3 -- Insert" << endl;
    cout << "4 -- Delete" << endl;
    cout << "5 -- IsEmpty" << endl;
    cout << "6 -- Length" << endl;
    cout << "7 -- Print" << endl;

    List L1;
    L1.InsertFirst(Node(0));
    L1.Insert(Node(1),L1.GetNode(0));

    int cmd,num1, num2;
    do
    {
        cin >> cmd;
        switch (cmd)
        {
        case 0:
            cout << "Thank you"<< endl;
            return 0;
            break;
        case 1:
            cout << "Enter int to insert first:";
            cin >> num;
            L1.InsertFirst(Node(num));
            break;
        case 2:
            L1.DeleteFirst();
            cout << "First Node deleted" << endl;
            break;
        case 3:
            cout << "Enter int to insert:";
            cin >> num1;
            cout << "Enter which key value you want to be inserted after";
            cin >> num2;
            L1.Insert(Node(num),L1.GetNode(num2));
            break;
        case 4:
            cout << "Enter int to delete:";
            cin >> num1;
            L1.Delete(num1);
            break;
        case 5:
            /* code */
            break;
        case 6:
            /* code */
            break;
        case 7:
            /* code */
            break;
        
        
        default:
            break;
        }
    } while (/* condition */);
    
    

    return 0;

}