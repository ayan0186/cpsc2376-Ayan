#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

// Base Class: Employee
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string name, int id) : name(name), id(id) {}

    virtual ~Employee() {}

    virtual double calculateSalary() const = 0; // Pure virtual function

    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name;
    }
};

// SalariedEmployee derived class
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Salaried, Monthly Salary: $" << calculateSalary() << endl;
    }
};

// HourlyEmployee derived class
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Hourly, Hours Worked: " << hoursWorked
             << ", Hourly Rate: $" << hourlyRate
             << ", Salary: $" << calculateSalary() << endl;
    }
};

// CommissionEmployee derived class
class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Commission, Base Salary: $" << baseSalary
             << ", Sales: $" << salesAmount
             << ", Commission Rate: " << commissionRate * 100 << "%"
             << ", Salary: $" << calculateSalary() << endl;
    }
};

int main() {
    vector<Employee*> employees;

    ifstream file("employees.txt");
    if (!file) {
        cerr << "Error opening file: employees.txt" << endl;
        return 1;
    }

    string type;
    while (file >> type) {
        int id;
        string name;
        file >> id;
        file.ignore(); // Ignore the space between id and name
        getline(file, name); // Read the name

        if (type == "Salaried") {
            double monthlySalary;
            file >> monthlySalary;
            employees.push_back(new SalariedEmployee(name, id, monthlySalary));
        } else if (type == "Hourly") {
            double hourlyRate;
            int hoursWorked;
            file >> hourlyRate >> hoursWorked;
            employees.push_back(new HourlyEmployee(name, id, hourlyRate, hoursWorked));
        } else if (type == "Commission") {
            double baseSalary, salesAmount, commissionRate;
            file >> baseSalary >> salesAmount >> commissionRate;
            employees.push_back(new CommissionEmployee(name, id, baseSalary, salesAmount, commissionRate));
        } else {
            cerr << "Unknown employee type: " << type << endl;
            return 1;
        }
    }

    for (auto employee : employees) {
        employee->displayInfo();
        delete employee;
    }

    return 0;
}
