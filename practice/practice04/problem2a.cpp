#include <iostream>
using namespace std;

template <typename T> 
T calculate(T a, T b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    } else if (op == '/') {
        if (b == 0) {
            cout << "Error: Division by zero\n";
            return 0; // Return 0 or some other value as an error flag
        }
        return a / b;
    } else {
        cout << "Error: Invalid operator\n";
        return 0; // Return 0 for invalid operator
    }
}

int main() {
    double a, b; // Declare a and b explicitly as double for handling both int and double input
    char op;

    while (true) {
        cout << "Enter first number: ";
        cin >> a; 
        cout << "Enter second number: ";
        cin >> b;
        cout << "Select operator(+, -, *, /): ";
        cin >> op;
        cout << "Result: " << calculate(a, b, op) << endl;
    }

    return 0;
}
