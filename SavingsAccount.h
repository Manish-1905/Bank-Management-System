// SavingsAccount.h
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

using namespace std;

class SavingsAccount : public Account {
private:
    double interestRate; 

public:
    SavingsAccount(string accNum, string holder, double initialBalance, double rate)
        : Account(accNum, holder, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate;
        balance += interest;
        cout << "Interest of $" << interest << " applied to Account " << accountNumber << "\n";
    }

    double getInterestRate() const override { return interestRate; }
    string getAccountType() const override { return "S"; }

    void displayAccountInfo() const override {
        cout << "\n--- Savings Account Details ---\n"
             << "Account Number : " << accountNumber << "\n"
             << "Account Holder : " << accountHolder << "\n"
             << "Current Balance: $" << balance << "\n"
             << "Interest Rate  : " << (interestRate * 100) << "%\n"
             << "-------------------------------\n";
    }
};

#endif // SAVINGSACCOUNT_H