#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Employee {
public:
    string name;
    int id;

    Employee(string name, int id) : name(name), id(id) {}
    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name;
    }
    virtual ~Employee() {}
};

class SalariedEmployee : public Employee {
public:
    double monthlySalary;

    SalariedEmployee(string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {}

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Salaried, Monthly Salary: $" << fixed << setprecision(2) << monthlySalary << endl;
    }
};

class HourlyEmployee : public Employee {
public:
    double hourlyRate;
    int hoursWorked;

    HourlyEmployee(string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Hourly, Hours Worked: " << hoursWorked
             << ", Hourly Rate: $" << fixed << setprecision(2) << hourlyRate
             << ", Salary: $" << calculateSalary() << endl;
    }
};

class CommissionEmployee : public Employee {
public:
    double baseSalary;
    double salesAmount;
    double commissionRate;

    CommissionEmployee(string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {}

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Commission, Base Salary: $" << fixed << setprecision(2) << baseSalary
             << ", Sales: $" << salesAmount
             << ", Commission Rate: " << commissionRate * 100 << "%, Salary: $" << calculateSalary() << endl;
    }
};

int main() {
    vector<Employee*> employees;

    ifstream file("employees.txt");
    if (!file) {
        cerr << "Unable to open file: employees.txt" << endl;
        return 1;
    }

    string type;
    while (file >> type) {
        int id;
        string name;
        file >> id >> ws;
        getline(file, name);

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
    file.close();

    for (const auto& employee : employees) {
        employee->displayInfo();
    }

    for (auto employee : employees) {
        delete employee;
    }

    return 0;
}