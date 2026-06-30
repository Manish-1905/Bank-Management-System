// Account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <iostream>

using namespace std;

class Account {
protected:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string accNum, string holder, double initialBalance) 
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}

    virtual ~Account() {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into Account " << accountNumber << "\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    virtual bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from Account " << accountNumber << "\n";
            return true;
        }
        cout << "Insufficient funds or invalid amount for Account " << accountNumber << ".\n";
        return false;
    }

    // Getters
    double getBalance() const { return balance; }
    string getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }

    // Virtual getters for file writing
    virtual double getInterestRate() const { return 0.0; }
    virtual double getTransactionFee() const { return 0.0; }
    virtual string getAccountType() const = 0; 

    // Pure Virtual Function
    virtual void displayAccountInfo() const = 0;
};

#endif // ACCOUNT_H