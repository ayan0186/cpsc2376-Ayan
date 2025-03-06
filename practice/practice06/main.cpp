#include <iostream>
#include "fraction.cpp" 

using namespace std;

// Function to get a valid fraction
void getFraction(int &n, int &d) {
    cout << "Enter the numerator: ";
    cin >> n;

    cout << "Enter the denominator (non-zero): ";
    cin >> d;

    while (d == 0) { // Ensuring denominator is not zero
        cout << "Denominator cannot be zero. Please try again.\nEnter the denominator: ";
        cin >> d;
    }
}

int main() { 
    int choice, n, d; 
    Fraction f1(0,1);  // Initialize fraction properly

    while (true) { 
        cout << "\nCurrent Fraction: " << f1 << endl;
        cout << "1. Enter a fraction (n/d)\n";
        cout << "2. Add a fraction (n/d)\n";
        cout << "3. Subtract a fraction (n/d)\n";
        cout << "4. Multiply a fraction (n/d)\n";
        cout << "5. Divide a fraction (n/d)\n";
        cout << "6. Clear the fraction\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: 
                getFraction(n, d); 
                f1 = Fraction(n, d); 
                break;

            case 2: 
            case 3: 
            case 4: 
            case 5: {
                getFraction(n, d); 
                Fraction temp(n, d);  // Declare inside a block to avoid scope issues

                if (choice == 2) {
                    f1 = f1 + temp; 
                } else if (choice == 3) { 
                    f1 = f1 - temp; 
                } else if (choice == 4) { 
                    f1 = f1 * temp; 
                } else if (choice == 5) { 
                    f1 = f1 / temp; 
                }
                break;
            }

            case 6: 
                f1 = Fraction(0,1); 
                break; 

            case 7: 
                cout << "Exiting Program..." << endl; 
                return 0; 

            default: 
                cout << "Invalid choice, try again." << endl; 
        }
    } 
    return 0;
}
