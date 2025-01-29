#include <iostream>
#include <vector>
#include "menu_system.h"
//this file is for giving the functions commands
void displayMenu() {
    std::cout << "\nMenu Options:\n" << std::endl;
    std::cout << "1. Add an item to the vector\n" << std::endl;
    std::cout << "2. Print the vector\n" << std::endl;
    std::cout << "3. Double the vector\n" << std::endl;
    std::cout << "4. Find the sum\n" << std::endl;
    std::cout << "5. Print multiples of a number\n" << std::endl;
    std::cout << "6. Exit\n" << std::endl;
}

void addItem(std::vector<int>& vec) {
    int addNum; 
    std::cout << "Enter a Number: " << std::endl; 
    std::cin >> addNum; 
    vec.push_back(addNum); 
}

void printVec(const std::vector<int>& vec) {
    std::cout << "Vector Content: " << std::endl; 
    for(int num : vec) {
        std::cout << num << " " << std::endl; 
    }
}

void doubleVec(std::vector<int>& vec) {
    for(int& num : vec) {
        num *= 2; 
    }
std::cout << "Vector Has been doubled\n" << std::endl;
//print doubled vector
printVec(vec); 
}

void sumVec(std::vector<int>& vec){
    int sum = 0;
    for(int num : vec){
        sum += num;
    }
    std::cout << "Sum of the vector is: " << sum << std::endl; 
}

void mutliples(const std::vector<int>& vec){
    int divisor;

    std::cout << "Enter a number to find the divisors of: " << std::endl; 
    std::cin >> divisor; 
    
    for(int num : vec){
        if(num % divisor == 0) {
            std::cout << num << " " << std::endl; 
        }
    }
std::cout << "\n" << std::endl; 
}