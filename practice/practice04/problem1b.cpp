#include <iostream>
#include <string>

void greet(std::string name = "Guest", std::string prefix = "Hello"){ 
    std::cout << prefix << ", " << name << "!" << std::endl;
}

int main() {
    int choice;
    std::string name;
    std::string prefix; 

    do {
    std::cout << "1. Default Greet\n";
    std::cout << "2. Greet By Name\n";
    std::cout << "3. Custom Greet\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        greet();
        break;
    case 2: 
        std::cout << "Enter your name: ";
        std::cin >> name; 
        greet(name);
        break;
    case 3: 
        std::cout << "Enter your name: ";
        std::cin >> name;  
        std::cout << "Enter your prefix: ";
        std::cin >> prefix;
        greet(name, prefix);
        break;
    case 4:
        std::cout << "Exiting...\n";
        break;
    default:
        std::cout << "Invalid choice\n";
        ;
    }

}
    while(choice != 4); 

    return 0;
}
