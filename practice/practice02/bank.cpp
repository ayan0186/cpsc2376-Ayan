#include <iostream>
#include <fstream>
#include <iomanip>
#include "bank.h"

// Reads the balance from the file, or initializes it to $100 if the file doesn't exist
float readFromFile() {
    std::ifstream file("account_balance.txt");
    float balance = 100.00;  // Default balance

    if (file) {
        file >> balance;
        file.close();
    }
    return balance;
}

// Writes the balance to the file
void writeBalanceToFile(float balance) {
    std::ofstream file("account_balance.txt");
    if (file) {
        file << std::fixed << std::setprecision(2) << balance;  // Ensures two decimal places
        file.close();
    } else {
        std::cerr << "Error: Unable to write to file!" << std::endl;
    }
}

// Displays the current balance to the user
void checkBalance(float balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
}

// Deposits money into the account
void deposit(float& balance) {
    float amount;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;

    if (amount > 0) {
        balance += amount;
        std::cout << "Deposit successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        writeBalanceToFile(balance);  // Save the updated balance
    } else {
        std::cout << "Error: Deposit amount must be positive." << std::endl;
    }
}

// Withdraws money from the account
void withdraw(float& balance) {
    float amount;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        std::cout << "Withdrawal successful. Your new balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
        writeBalanceToFile(balance);  // Save the updated balance
    } else if (amount > balance) {
        std::cout << "Error: Insufficient funds. Your balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;
    } else {
        std::cout << "Error: Withdrawal amount must be positive." << std::endl;
    }
}
