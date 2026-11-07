#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;

class Employee {
private:
    char employeeID[10];
    char name[50];
    char designation[30];
    char department[30];
    double salary;

public:
    Employee() {
        memset(employeeID, 0, sizeof(employeeID));
        memset(name, 0, sizeof(name));
        memset(designation, 0, sizeof(designation));
        memset(department, 0, sizeof(department));
        salary = 0.0;
    }

    void read() {
        cout << "Enter Employee ID: ";
        cin.getline(employeeID, 10);

        cout << "Enter Name: ";
        cin.getline(name, 50);

        cout << "Enter Designation: ";
        cin.getline(designation, 30);

        cout << "Enter Department: ";
        cin.getline(department, 30);

        cout << "Enter Salary: ";
        cin >> salary;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    void display() {
        cout << setiosflags(ios::left) << setw(12) << employeeID
             << setw(30) << name
             << setw(20) << designation
             << setw(20) << department
             << resetiosflags(ios::left)
             << setiosflags(ios::right)
             << setw(10) << fixed << setprecision(2) << salary << endl;
        cout << resetiosflags(ios::right);
    }

    const char* getEmployeeID() const {
        return employeeID;
    }

    void markAsDeleted() {
        memset(employeeID, '*', 10 - 1);
        employeeID[10 - 1] = '\0';
        memset(name, 0, sizeof(name));
        memset(designation, 0, sizeof(designation));
        memset(department, 0, sizeof(department));
        salary = 0.0;
    }

    bool isDeleted() const {
        return (employeeID[0] == '*' || strlen(employeeID) == 0);
    }

    void writeToFile(fstream& file) {
        file.write(reinterpret_cast<char*>(this), sizeof(Employee));
    }

    void readFromFile(fstream& file) {
        file.read(reinterpret_cast<char*>(this), sizeof(Employee));
    }
};

void addEmployee(fstream& file);
void displayAllEmployees(fstream& file);
void searchEmployee(fstream& file);
void updateEmployee(fstream& file);
void deleteEmployee(fstream& file);
long getNumberOfActiveEmployees(fstream& file);
long getFileSize(fstream& file);

int main() {
    fstream file;
    char choice;
    const char* filename = "employees.dat";

    file.open(filename, ios::in | ios::out | ios::binary);

    if (!file) {
        file.open(filename, ios::out | ios::binary);
        file.close();
        file.open(filename, ios::in | ios::out | ios::binary);
        if (!file) {
            cout << "Error creating or opening file! Exiting." << endl;
            return 1;
        }
    }

    do {
        cout << "\n--- Employee Management System ---" << endl;
        cout << "1. Add New Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Update Employee Details" << endl;
        cout << "5. Delete Employee" << endl;
        cout << "6. Get Number of Active Employees" << endl;
        cout << "7. Get File Size" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case '1':
                addEmployee(file);
                break;
            case '2':
                displayAllEmployees(file);
                break;
            case '3':
                searchEmployee(file);
                break;
            case '4':
                updateEmployee(file);
                break;
            case '5':
                deleteEmployee(file);
                break;
            case '6':
                cout << "Number of active employees: " << getNumberOfActiveEmployees(file) << endl;
                break;
            case '7':
                cout << "File size: " << getFileSize(file) << " bytes" << endl;
                break;
            case '8':
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '8');

    file.close();
    return 0;
}

void addEmployee(fstream& file) {
    Employee emp;
    emp.read();
    file.seekp(0, ios::end);
    emp.writeToFile(file);
    cout << "Employee added successfully!" << endl;
    file.flush();
}

void displayAllEmployees(fstream& file) {
    Employee emp;
    file.clear();
    file.seekg(0, ios::beg);

    cout << "\n--- Employee List ---" << endl;
    cout << setiosflags(ios::left) << setw(12) << "ID"
         << setw(30) << "Name"
         << setw(20) << "Designation"
         << setw(20) << "Department"
         << resetiosflags(ios::left)
         << setiosflags(ios::right)
         << setw(10) << "Salary" << endl;
    cout << setfill('-') << setw(92) << "" << setfill(' ') << endl;

    bool foundActive = false;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (!emp.isDeleted()) {
            emp.display();
            foundActive = true;
        }
    }
    if (!foundActive) {
        cout << "No active employees to display." << endl;
    }
    file.clear();
}

void searchEmployee(fstream& file) {
    char searchID[10];
    cout << "Enter Employee ID to search: ";
    cin.getline(searchID, 10);

    Employee emp;
    file.clear();
    file.seekg(0, ios::beg);

    bool found = false;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (!emp.isDeleted() && strcmp(emp.getEmployeeID(), searchID) == 0) {
            cout << "\nEmployee Found:" << endl;
            emp.display();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID '" << searchID << "' not found or is deleted." << endl;
    }
    file.clear();
}

void updateEmployee(fstream& file) {
    char updateID[10];
    cout << "Enter Employee ID to update: ";
    cin.getline(updateID, 10);

    Employee emp;
    file.clear();
    file.seekg(0, ios::beg);

    long pos = -1;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (!emp.isDeleted() && strcmp(emp.getEmployeeID(), updateID) == 0) {
            found = true;
            pos = file.tellg() - sizeof(Employee);
            cout << "\nEmployee Found. Enter new details:" << endl;
            emp.read();
            
            file.seekp(pos, ios::beg);
            emp.writeToFile(file);
            cout << "Employee details updated successfully!" << endl;
            file.flush();
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID '" << updateID << "' not found or is deleted for update." << endl;
    }
    file.clear();
}

void deleteEmployee(fstream& file) {
    char deleteID[10];
    cout << "Enter Employee ID to delete: ";
    cin.getline(deleteID, 10);

    Employee emp;
    file.clear();
    file.seekg(0, ios::beg);

    long pos = -1;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (!emp.isDeleted() && strcmp(emp.getEmployeeID(), deleteID) == 0) {
            found = true;
            pos = file.tellg() - sizeof(Employee);
            
            emp.markAsDeleted();
            
            file.seekp(pos, ios::beg);
            emp.writeToFile(file);
            cout << "Employee with ID '" << deleteID << "' marked as deleted." << endl;
            file.flush();
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID '" << deleteID << "' not found or already deleted." << endl;
    }
    file.clear();
}

long getNumberOfActiveEmployees(fstream& file) {
    file.clear();
    long currentPos = file.tellg();
    file.seekg(0, ios::beg);

    long count = 0;
    Employee emp;
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (!emp.isDeleted()) {
            count++;
        }
    }

    file.seekg(currentPos);
    file.clear();
    return count;
}

long getFileSize(fstream& file) {
    file.clear();
    long currentPos = file.tellg();
    file.seekg(0, ios::end);
    long fileSize = file.tellg();
    file.seekg(currentPos);
    file.clear();
    return fileSize;
}