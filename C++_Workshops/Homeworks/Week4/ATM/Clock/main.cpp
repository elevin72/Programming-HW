/* 
Program Name:
Description of program:
Course Name: C++ Workshops
Exercise# and Question#:
Name: Eli Levin 341318228
Creation date: 15/05/2020
Last Modification date:
*/
#include <iostream>
#include "clock.h"
#include "account.h"
using namespace std;

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size)
{
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number)
		i++;
    if (i == size){
        throw string("ERROR: no such account number!");
    }
	cout << "please enter the code: ";
	cin >> code;
	if (bank[i].getCode() == code) //this maybe should be a while loop
		return i;
    else {
        throw string("ERROR: wrong code!");
    }
}

void printTransaction(Account a, action ac, Clock& c)
{
	cout << c << "\t";
	switch (ac)
	{
	case balance: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit:
	case withdraw: cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit:
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw:
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
    default:
        break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	c += 20;
	printTransaction(bank[i], balance, c);
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount;
	bank[i].deposit(amount);
	c += 30;
	printTransaction(bank[i], deposit, c);
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	bank[i].withdraw(amount);
	c += 50;
	printTransaction(bank[i], withdraw, c);
}
int main()
{
	Clock c(8);
    c += 3670;
    cout << c;
	Account bank[10];
	cout << "enter account number and code for 10 accounts:\n";
	for (int i = 0; i < 10; i++)
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n";
		}
		catch (string e)
		{
			cout << c << '\t' << e;
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		switch (ac)
		{
		case balance: getBalance(bank, 10, c);
			break;
		case withdraw:
            try{
                cashWithdraw(bank, 10, c);
            }
            catch(string e)
            {
                cout << c << '\t' << e << '\n';
            }
			break;
		case deposit:
            try{
                cashDeposit(bank, 10, c);
            }
            catch(string e)
            {
                cout << c << '\t' << e << '\n';
            }
			break;
		case sumDeposit:c += 60;
			printTransaction(bank[0], sumDeposit, c);
			break;
		case sumWithdraw:c += 60;
			printTransaction(bank[0], sumWithdraw, c);
            break;
        default:
            break;
		}
		ac = menu();
	}
	return 0;
}
