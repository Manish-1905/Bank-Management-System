// Bank.h
#ifndef BANK_H
#define BANK_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"

using namespace std;

class Bank {
private:
    vector<Account*> accounts;

    Account* findAccount(const string& accNum) {
        for (Account* acc : accounts) {
            if (acc->getAccountNumber() == accNum) {
                return acc;
            }
        }
        return nullptr;
    }

public:
    ~Bank() {
        for (Account* acc : accounts) {
            delete acc;
        }
        accounts.clear();
    }

    void createSavingsAccount(string accNum, string holder, double balance, double rate) {
        if (findAccount(accNum) != nullptr) {
            cout << "Error: Account number " << accNum << " already exists!\n";
            return;
        }
        accounts.push_back(new SavingsAccount(accNum, holder, balance, rate));
        cout << "Savings Account '" << accNum << "' successfully opened.\n";
    }

    void createCheckingAccount(string accNum, string holder, double balance, double fee) {
        if (findAccount(accNum) != nullptr) {
            cout << "Error: Account number " << accNum << " already exists!\n";
            return;
        }
        accounts.push_back(new CheckingAccount(accNum, holder, balance, fee));
        cout << "Checking Account '" << accNum << "' successfully opened.\n";
    }

    void depositToAccount(string accNum, double amount) {
        Account* acc = findAccount(accNum);
        if (acc != nullptr) {
            acc->deposit(amount);
        } else {
            cout << "Transaction Failed: Account " << accNum << " not found.\n";
        }
    }

    void withdrawFromAccount(string accNum, double amount) {
        Account* acc = findAccount(accNum);
        if (acc != nullptr) {
            acc->withdraw(amount);
        } else {
            cout << "Transaction Failed: Account " << accNum << " not found.\n";
        }
    }

    void triggerInterestForAccount(string accNum) {
        Account* acc = findAccount(accNum);
        if (acc != nullptr) {
            SavingsAccount* savingsAcc = dynamic_cast<SavingsAccount*>(acc);
            if (savingsAcc != nullptr) {
                savingsAcc->applyInterest();
            } else {
                cout << "Operation failed: Account " << accNum << " is not a Savings Account.\n";
            }
        } else {
            cout << "Account not found.\n";
        }
    }

    void displayAllAccounts() const {
        if (accounts.empty()) {
            cout << "The bank database is empty.\n";
            return;
        }
        cout << "\n===============================";
        cout << "\n  BANKING SYSTEM DATABASE";
        cout << "\n===============================";
        for (const Account* acc : accounts) {
            acc->displayAccountInfo();
        }
    }

    void saveToFile(const string& filename = "bank_data.txt") {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error opening database file for writing.\n";
            return;
        }

        for (Account* acc : accounts) {
            double extra = (acc->getAccountType() == "S") ? acc->getInterestRate() : acc->getTransactionFee();
            outFile << acc->getAccountType() << ","
                    << acc->getAccountNumber() << ","
                    << acc->getAccountHolder() << ","
                    << acc->getBalance() << ","
                    << extra << "\n";
        }
        outFile.close();
        cout << "Database successfully saved to " << filename << "\n";
    }

    void loadFromFile(const string& filename = "bank_data.txt") {
        ifstream inFile(filename);
        if (!inFile) {
            return; 
        }

        for (Account* acc : accounts) delete acc;
        accounts.clear();

        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string type, accNum, holder, balStr, extraStr;

            getline(ss, type, ',');
            getline(ss, accNum, ',');
            getline(ss, holder, ',');
            getline(ss, balStr, ',');
            getline(ss, extraStr, ',');

            if (type.empty()) continue;

            double balance = stod(balStr);
            double extra = stod(extraStr);

            if (type == "S") {
                accounts.push_back(new SavingsAccount(accNum, holder, balance, extra));
            } else if (type == "C") {
                accounts.push_back(new CheckingAccount(accNum, holder, balance, extra));
            }
        }
        inFile.close();
        cout << "Database loaded successfully from persistent storage.\n";
    }
};

#endif // BANK_H