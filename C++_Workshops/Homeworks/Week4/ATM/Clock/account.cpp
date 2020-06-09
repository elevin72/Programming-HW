#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP
#include <iostream>
#include "account.h"
using namespace std;

int Account::sumWithdraw = 0;
int Account::sumDeposit = 0;

//constuctors
Account::Account(){
    _accountNumber = 0;
    _code = 0;
    _balance = 0;
}

Account::Account(int accNum, int code, int bal) {
        _accountNumber = accNum;
        setCode(code);
        _balance = 0;
}

void Account::setBalance(int bal){
    _balance = bal;
}

void Account::setCode(int code){
    if(code < 1000 || code > 9999){
            throw string("ERROR: code must be of 4 digits!");
    }
    _code = code; 
}

int Account::getBalance() const {
    return _balance;
}

int Account::getCode() const {
    return _code;
}

int Account::getAccountNumber() const {
    return _accountNumber; 
}

istream& operator>>(istream& in, Account& a){
    int accNum,code;
    in >> accNum >> code;
    a._accountNumber = accNum;
    a.setCode(code);
    return in;

}

void Account::withdraw(int nis) {
    if (_balance - nis < -6000) {
        throw string("ERROR: cannot have less than - 6000 NIS");
    } 
    if (nis > 2500) {
        throw string("ERROR: cannot withdraw more than 2500 NIS!");
    }
    _balance -= nis;
    Account::sumWithdraw += nis;
}

void Account::deposit(int nis) {
    if (nis > 10000) {
        throw string("ERROR: cannot deposit more than 10000 NIS!");
	}
    _balance += nis;
    sumDeposit += nis;
}

int Account::getSumWithdraw() {
    return sumWithdraw;
}

int Account::getSumDeposit() {
    return sumDeposit;
}

#endif