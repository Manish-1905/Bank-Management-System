# Persistent Digital Banking System

A console-based Digital Banking System implemented in C++ that demonstrates core Object-Oriented Programming (OOP) principles. The system allows users to create and manage different types of bank accounts, perform financial transactions, and automatically persist all database changes to a local file.

## 🚀 Features

- **Interactive Console Menu:** Easy-to-use text interface for executing all banking operations.
- **Dynamic Account Management:** Supports both **Savings Accounts** (with interest accumulation) and **Checking Accounts** (with automated transaction fees).
- **Persistent Data Storage:** Automatically loads existing database states on startup and saves all account records to `bank_data.txt` upon exit.
- **Robust Input Handling:** Safe validation loops to handle incorrect user inputs without crashing.

## 🏗️ OOP Concepts Demonstrated

- **Abstraction:** Implemented via an abstract base class (`Account`) containing pure virtual functions to enforce a consistent operational structure.
- **Inheritance:** `SavingsAccount` and `CheckingAccount` leverage public inheritance to inherit core functionalities while extending unique features.
- **Polymorphism:** Utilizing a singular collection of base class pointers (`vector<Account*>`) to dynamically invoke derived class behaviors at runtime (e.g., executing account-specific withdrawal logic).
- **Encapsulation:** Restricting direct access to sensitive financial data (`balance`, `accountNumber`) using data hiding (`protected` and `private` modifiers) paired with secure public methods.

## 📁 Project Structure

- `Account.h` - Abstract base class defining common account traits.
- `SavingsAccount.h` - Derived class with unique interest calculation logic.
- `CheckingAccount.h` - Derived class implementing automated transaction fees.
- `Bank.h` - Manager class coordinating account collections and file I/O operations.
- `main.cpp` - Entry point containing the runtime interactive menu application loop.

## 🛠️ How to Compile and Run

Open your terminal in the project directory and execute the following commands:

```bash
# Compile the project
g++ main.cpp

# Run the executable
./a.out
