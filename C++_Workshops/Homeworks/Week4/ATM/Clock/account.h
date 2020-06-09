#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

class Account {
    private:
        int _accountNumber;
        int _code;
        int _balance;

        void setCode(int code);
    public:
        Account();
        Account(int accNum, int code, int bal);

        //setter
        void setBalance(int bal);

        //getters
        int getBalance() const;
        int getCode() const; //this should arguably be private
        int getAccountNumber() const;
        
        // input operator
        friend std::istream& operator>>(std::istream& in, Account& a);

        //other functions
        void withdraw(int nis);
        void deposit(int nis);

        //static fields and methods
        static int sumWithdraw;
        static int sumDeposit;

        static int getSumWithdraw();
        static int getSumDeposit();
};

#endif