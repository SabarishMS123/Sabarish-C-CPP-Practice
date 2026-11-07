#include <iostream>
#include <string>
#include <variant> // Required for std::variant

using namespace std;

// Combined Employee class template
template <typename IDType>
class Employee {
public:
    // Constructor
    Employee(IDType id, const string& name, double sal,
             optional<string> dept = nullopt, optional<int> lvl = nullopt, optional<string> title = nullopt)
        : id_(id), name_(name), sal_(sal), dept_(dept), lvl_(lvl), title_(title) {}

    // Display employee information
    virtual void display() const {
        cout << "ID: " << id_ << ", Name: " << name_ << ", Salary: $" << sal_;
        if (dept_.has_value()) cout << ", Department: " << dept_.value();
        if (lvl_.has_value()) cout << ", Level: " << lvl_.value();
        if (title_.has_value()) cout << ", Title: " << title_.value();
    }

    // Getters
    IDType getId() const { return id_; }
    const string& getName() const { return name_; }
    double getSalary() const { return sal_; }
    optional<string> getDept() const { return dept_; }
    optional<int> getLvl() const { return lvl_; }
    optional<string> getTitle() const{ return title_; }

    // Increment salary, handles different positions
    virtual void incrementSalary(double pct) {
        if (pct > 0) {
            double increment = sal_ * (pct / 100.0);
             if (lvl_.has_value()) {
                sal_ += increment + sal_ * (3.0 / 100.0); // Manager
            } else if (title_.has_value()) {
                 sal_ += increment + sal_ * (7.0 / 100.0); // Board Directive
            }
            else{
                 sal_ += increment;
            }
        }
    }

protected:
    IDType id_;
    string name_;
    double sal_;
    optional<string> dept_; // Department (for Manager)
    optional<int> lvl_;    // Level (for Manager)
    optional<string> title_;  // Title (for Board Directive)
};

// Function to get integer input
int getIntInput(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter an integer.\n";
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }
    return val;
}

// Function to get double input
double getDoubleInput(const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        cin >> val;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
        } else {
            cin.ignore(10000, '\n');
            break;
        }
    }
    return val;
}

int main() {
    const int MAX_EMPS = 100;
    Employee<int>* employees[MAX_EMPS];
    int numEmps = 0;

    numEmps = getIntInput("Enter the number of employees: ");
    if (numEmps > MAX_EMPS) {
        cout << "Too many employees. Maximum is " << MAX_EMPS << endl;
        return 1;
    }

    for (int i = 0; i < numEmps; ++i) {
        cout << "\n--- Employee " << i + 1 << " Details ---\n";
        int id = getIntInput("Enter employee ID: ");
        string name;
        cout << "Enter employee name: ";
        getline(cin >> ws, name);
        double sal = getDoubleInput("Enter employee salary: ");

        int pos = getIntInput("Enter employee position (1: Employee, 2: Manager, 3: Board Directive): ");
        Employee<int>* emp = nullptr;

        switch (pos) {
            case 1: // Employee
                emp = new Employee<int>(id, name, sal);
                break;
            case 2: { // Manager
                string dept;
                cout << "Enter manager's department: ";
                getline(cin >> ws, dept);
                int lvl = getIntInput("Enter manager's level: ");
                emp = new Employee<int>(id, name, sal, dept, lvl);
                break;
            }
            case 3: { // Board Directive
                string title;
                cout << "Enter board directive's title: ";
                getline(cin >> ws, title);
                emp = new Employee<int>(id, name, sal, nullopt, nullopt, title);
                break;
            }
            default:
                cout << "Invalid position. Creating a default employee.\n";
                emp = new Employee<int>(id, name, sal);
                break;
        }
        employees[i] = emp;
    }

    // Display employee details
    cout << "\n--- Employee Details ---\n";
    for (int i = 0; i < numEmps; ++i) {
        employees[i]->display();
        cout << endl;
    }

    // Apply and display increments
    cout << "\n--- Applying Increments ---\n";
     for (int i = 0; i < numEmps; ++i) {
        double pct = 5.0;
        employees[i]->incrementSalary(pct);
    }

    cout << "\n--- Employee Details After Increments ---\n";
    for (int i = 0; i < numEmps; ++i) {
        employees[i]->display();
        cout << endl;
    }

    // Clean up
    for (int i = 0; i < numEmps; ++i) {
        delete employees[i];
    }

    return 0;
}
