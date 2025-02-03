#include <iostream>
#include <iomanip>
#include "bank.h"

int main() {
    std::cout << "Welcome to Your Bank Account!" << std::endl;

    // Read balance from the file or initialize it if the file doesn't exist
    float balance = readFromFile();
    
    // Display initial message with current balance
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;

    // Menu loop
    bool running = true;
    while (running) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";

        std::cout << "Enter your choice: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                deposit(balance);
                break;
            case 3:
                withdraw(balance);
                break;
            case 4:
                running = false;  // Exit the program
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    std::cout << "Thank you for using Your Bank Account!" << std::endl;
    return 0;
}
