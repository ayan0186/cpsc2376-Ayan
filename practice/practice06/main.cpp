#include <iostream>
#include "fraction.h" 

using namespace std;

void getFraction(int &n, int &d) {
    cout << "Enter the numerator: ";
    cin >> n;
    cout << "Enter the denominator: ";
    cin >> d;

    if(d == 0) {
        cout << "Denominator cannot be zero. Please try again." << endl;
        getFraction(n, d);
    }
}

int main() { 
int choice, n, d; 
Fraction f1(n,d); 
while(true)
{ 
    cout << "Current Fraction: " << f1 << endl;
    cout << "1. Enter a fraction (n/d): ";
    cout << "2. Add a fraction (n/d): ";
    cout << "3. Subtract a fraction (n/d): ";
    cout << "4. Multiply a fraction (n/d): ";
    cout << "5. Divide a fraction (n/d): ";
    cout << "6. Clear the fraction: ";
    cout << "7. Exit: ";
    cout << "Enter your choice: ";

    cin >> choice;
    
    switch(choice) {
        case 1: 
        getFraction(n,d); 
        f1 = Fraction(n,d); 

        case 2: 
        case 3: 
        case 4: 
        case 5: 

        getFraction(n,d); 
        Fraction temp(n,d); 
        if(choice == 2){
            f1 = f1 + temp; 
        }
        else if(choice == 3){ 
            f1 = f1 - temp; 
        }
        else if(choice == 4){ 
            f1 = f1 * temp; 
        }
        else if(choice == 5){ 
            f1 = f1 / temp; 
        }
        break; 

        case 6: 
        f1 = Fraction(0,1)

        case 7: 
        cout << "Exiting Program..."; 
        return 0; 

        default: 
        cout << "Invaild choice, try again"; 

    }

} 
    return 0;
}