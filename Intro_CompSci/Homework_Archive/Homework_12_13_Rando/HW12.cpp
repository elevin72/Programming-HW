/* 
File Name: HW12.cpp
Description of program: Keep track of inventory of store
Course Name: Introduction to Computer Science
Exercise# and Question#: 12, 1
Name: Eli Levin 341318228
Creation date: 27-1-20
Last Modification date: 29-1-20
*/
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Item
{
    int code;
    char name[21];
    int curAmount;
    int minAmount;
    int price; //always divide by 100 and cast to float before outputting price
};

void AddItem(Item* store, int maxItems, int& numItems);
void Print(Item* store, int numItems);
void FindPrice(Item* store, int numItems);
void Sold(Item* store, int numItems);
void Order(Item* store, int numItems);

enum cases{EXIT,ADD,FIND,SOLD,ORDER,PRINT};

int main()
{ 
    Item* store;
    int maxItems;
    int numItems = 0;
    int choice;
    cout << "enter max number of items: " << endl;
    cin >> maxItems;
    store = new Item[maxItems];

    do {
		cout << "enter 0-5:\n";

		cin >> choice;

		switch (choice) {
		case EXIT:	
        break;

		case ADD:	
            AddItem(store, maxItems, numItems);
			break;

		case FIND: 	//findPrice(store, numItems);
            FindPrice(store, numItems);
			break;

		case SOLD:	//sold(store, numItems);
            Sold(store, numItems);
			break;

		case ORDER:	//order(store, numItems);
            Order(store, numItems);
			break;

		case PRINT: 
            Print(store, numItems);
			break;

		default: 	cout << "ERROR" << endl;
		}
	} while (choice != 0);
	return 0;
}

void AddItem(Item* store, int maxItems, int& numItems){

    //we may want to check if possible to enter new item before asking user for all this data

    Item newItem;

    cout << "enter code:" << endl;
    cin >> newItem.code; 

    cout << "enter name:" << endl;
    cin.ignore(100, '\n'); //otherwise getline() won't work
    cin.getline(newItem.name, 20);

    cout << "enter amount:" << endl;
    cin >> newItem.curAmount;

    cout << "enter minimum amount:" << endl;
    cin >> newItem.minAmount;

    float newPrice;
    cout << "enter price:" << endl;
    cin >> newPrice;
    //cin.ignore(100, '\n');
    newItem.price = newPrice*100;

    for (int i = 0; i < numItems; i++){
        if (store[i].code == newItem.code){
            if (strcmp(store[i].name, newItem.name) != 0){
                cout << "ERROR" << endl;
                return;
            }
            else {
                store[i].curAmount += newItem.curAmount;
                return; 
            }
        }
    }

    //not sure if this should go here
    if(maxItems == numItems){
        cout << "ERROR" << endl;
        return;
    }

    store[numItems++] = newItem; //increment number of items and say that the next uninitialized Item in store should be equal to the item created in this function
}

void Print(Item* store, int numItems){
    for (int i = 0; i < numItems; i++){
        cout << "name: " << store[i].name << endl;
        cout << "code: " << store[i].code << endl;
        cout << "amount: " << store[i].curAmount << endl;
        cout << "minimum amount: " << store[i].minAmount << endl;
        cout << fixed << setprecision(2) << "price: " << (float)store[i].price/100 << endl << endl; //floats loose accurracy, therefore when dealing with important decimal points, such as money, store as whole number and just cast  to float divide by 100 before printing
    }
}

void FindPrice(Item* store, int numItems){
    int desiredCode;
    cout << "enter code:" << endl;
    cin >> desiredCode;
    for (int i = 0; i < numItems; i++){
        if(desiredCode == store[i].code){
            cout << "price: " << store[i].price << endl;
            return; // since there can only be one item with that code
        }
    }
    cout << "ERROR" << endl;
}

void Sold(Item* store, int numItems){
    int desiredCode;
    int desiredAmount;
    cout << "enter code:" << endl;
    cin >> desiredCode;
    cout << "enter amount:" << endl;
    cin >> desiredAmount;
    for (int i = 0; i < numItems; i++){
        if(desiredCode == store[i].code){
            store[i].curAmount -= desiredAmount; // subtract desiredAmount from the curAmount of current Item
            return;
        }
    }
    cout << "ERROR" << endl;
}

void Order(Item* store, int numItems){
    for (int i = 0; i < numItems; i++){
        if(store[i].curAmount < store[i].minAmount){ // if curAmount is below minAmount
            int toOrder = (store[i].minAmount - store[i].curAmount) + 5; 
            store[i].curAmount += toOrder;
            cout << "item name: " << store[i].name << endl
            << "code: " << store[i].code << endl 
            << "amount to order: " << toOrder << endl;
        }
    }
}