#include <iostream>
#include <vector>
#include "menu_system.cpp"

int main() {
    std::vector<int> myVector = {10, 30, 20, 40, 50};
    int choice;

    do {
        displayMenu(); 
        std::cout << "Enter your choice: " << std::endl; 
        std::cin >> choice; 
        
        switch(choice) {
            case 1: addItem(myVector); 
            break; 

            case 2: printVec(myVector); 
            break;

            case 3: doubleVec(myVector);
            break; 

            case 4: sumVec(myVector); 
            break; 

            case 5: mutliples(myVector);
            break; 

            case 6: 
            std::cout << "Exiting Program..." << std::endl;
            break; 

            default: 
            std::cout << "Invalid input try again" << std::endl; 
            break;
        }

    }
    while(choice != 6); 



    return 0; 
}