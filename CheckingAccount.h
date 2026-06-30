// CheckingAccount.h
#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

using namespace std;

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(string accNum, string holder, double initialBalance, double fee)
        : Account(accNum, holder, initialBalance), transactionFee(fee) {}

    bool withdraw(double amount) override {
        double totalDeduction = amount + transactionFee;
        
        if (amount > 0 && totalDeduction <= balance) {
            balance -= totalDeduction;
            cout << "Withdrew $" << amount << " from Account " << accountNumber 
                 << " (Fee of $" << transactionFee << " applied)\n";
            return true;
        }
        cout << "Transaction failed: Insufficient funds to cover fee for Account " << accountNumber << ".\n";
        return false;
    }

    double getTransactionFee() const override { return transactionFee; }
    string getAccountType() const override { return "C"; }

    void displayAccountInfo() const override {
        cout << "\n--- Checking Account Details ---\n"
             << "Account Number : " << accountNumber << "\n"
             << "Account Holder : " << accountHolder << "\n"
             << "Current Balance: $" << balance << "\n"
             << "Transaction Fee: $" << transactionFee << "\n"
             << "--------------------------------\n";
    }
};

#endif // CHECKINGACCOUNT_H