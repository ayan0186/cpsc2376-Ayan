#include <iostream>
#include <iomanip>
#include "bank.cpp"

int main() {
    std::cout << "Welcome to Your Bank Account!" << std::endl;

    // Read balance from the file or initialize it if the file doesn't exist
    float balance = readFromFile();
    
    // Display initial message with current balance
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << std::endl;

    // Menu loop
    char choice;
    do {
        std::cout << "Please select an option:" << std::endl;
        std::cout << "1. Check balance" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Deposit" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;

        switch (choice) {
            case '1':
                checkBalance(balance);
                break;
            case '2':
                withdraw(balance);
                break;
            case '3':
                deposit(balance);
                break;
            case '4':
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (choice != '4');

    std::cout << "Thank you for using Your Bank Account!" << std::endl;
    return 0;
}
