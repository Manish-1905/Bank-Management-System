// main.cpp
#include "Bank.h"
#include <iostream>
#include <string>

using namespace std;

void showMenu() {
    cout << "\n=================================\n";
    cout << "    DIGITAL BANKING INTERFACE    \n";
    cout << "=================================\n";
    cout << "1. Open Savings Account\n";
    cout << "2. Open Checking Account\n";
    cout << "3. Deposit Money\n";
    cout << "4. Withdraw Money\n";
    cout << "5. Apply Savings Interest\n";
    cout << "6. Display All Accounts\n";
    cout << "7. Save & Exit\n";
    cout << "=================================\n";
    cout << "Enter your choice (1-7): ";
}

int main() {
    Bank myBank;
    myBank.loadFromFile();
    
    int choice;
    string accNum, holder;
    double amount, balance, fee, rate;

    while (true) {
        showMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            string dummy;
            cin >> dummy;
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue;
        }

        switch (choice) {
            case 1:
                cout << "\n--- Open Savings Account ---\n";
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holder);
                cout << "Enter Initial Balance: $";
                cin >> balance;
                cout << "Enter Interest Rate (e.g., 0.04 for 4%): ";
                cin >> rate;
                
                myBank.createSavingsAccount(accNum, holder, balance, rate);
                break;

            case 2:
                cout << "\n--- Open Checking Account ---\n";
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Account Holder Name: ";
                cin.ignore();
                getline(cin, holder);
                cout << "Enter Initial Balance: $";
                cin >> balance;
                cout << "Enter Transaction Fee: $";
                cin >> fee;
                
                myBank.createCheckingAccount(accNum, holder, balance, fee);
                break;

            case 3:
                cout << "\n--- Deposit Money ---\n";
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Deposit: $";
                cin >> amount;
                
                myBank.depositToAccount(accNum, amount);
                break;

            case 4:
                cout << "\n--- Withdraw Money ---\n";
                cout << "Enter Account Number: ";
                cin >> accNum;
                cout << "Enter Amount to Withdraw: $";
                cin >> amount;
                
                myBank.withdrawFromAccount(accNum, amount);
                break;

            case 5:
                cout << "\n--- Apply Savings Interest ---\n";
                cout << "Enter Account Number: ";
                cin >> accNum;
                
                myBank.triggerInterestForAccount(accNum);
                break;

            case 6:
                myBank.displayAllAccounts();
                break;

            case 7:
                myBank.saveToFile();
                cout << "\nThank you for using our Digital Banking Interface. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice! Please choose an option between 1 and 7.\n";
        }
    }

    return 0;
}