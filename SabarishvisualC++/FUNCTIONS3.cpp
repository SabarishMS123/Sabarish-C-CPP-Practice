#include <iostream>
using namespace std;

// Structure to represent a student
struct Student {
    string name;
    int marks;
    char grade;
};

// Function declarations
void addMarks(int &marks, int addedMarks);                   // Call by reference
void updateMarks(int &marks, int updatedMarks);              // Call by reference
void displayStudentInfo(const Student &student);             // Call by reference
void calculateGrade(Student &student);                       // Call by reference

int main() {
    int numberOfStudents;
    cout << "Enter the number of students: ";
    cin >> numberOfStudents;

    Student* students = new Student[numberOfStudents];

    for (int i = 0; i < numberOfStudents; ++i) {
        cout << "Enter name for student " << (i + 1) << ": ";
        cin >> students[i].name;
        cout << "Enter initial marks for " << students[i].name << ": ";
        cin >> students[i].marks;
        calculateGrade(students[i]);  // Calculate initial grade
    }

    int choice;
    bool running = true;

    while (running) {
        cout << "Student Management System" << endl;
        cout << "1. Add Marks" << endl;
        cout << "2. Update Marks" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    int studentIndex, marks;
                    cout << "Enter student index: ";
                    cin >> studentIndex;
                    if (studentIndex >= 0 && studentIndex < numberOfStudents) {
                        cout << "Enter marks to add: ";
                        cin >> marks;
                        addMarks(students[studentIndex].marks, marks);  // Add marks to student
                        calculateGrade(students[studentIndex]);         // Calculate grade after adding marks
                    } else {
                        cout << "Invalid student index." << endl;
                    }
                }
                break;
            case 2:
                {
                    int studentIndex, marks;
                    cout << "Enter student index: ";
                    cin >> studentIndex;
                    if (studentIndex >= 0 && studentIndex < numberOfStudents) {
                        cout << "Enter updated marks: ";
                        cin >> marks;
                        updateMarks(students[studentIndex].marks, marks); // Update student marks
                        calculateGrade(students[studentIndex]);           // Calculate grade after updating marks
                    } else {
                        cout << "Invalid student index." << endl;
                    }
                }
                break;
            case 3:
                {
                    int studentIndex;
                    cout << "Enter student index: ";
                    cin >> studentIndex;
                    if (studentIndex >= 0 && studentIndex < numberOfStudents) {
                        displayStudentInfo(students[studentIndex]);      // Display student information
                    } else {
                        cout << "Invalid student index." << endl;
                    }
                }
                break;
            case 4:
                delete[] students;  // Release the allocated memory
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}

// Function definitions

// Call by reference
void addMarks(int &marks, int addedMarks) {
    marks += addedMarks;
    cout << "Added " << addedMarks << " marks. Updated marks: " << marks << endl;
}

// Call by reference
void updateMarks(int &marks, int updatedMarks) {
    marks = updatedMarks;
    cout << "Updated marks: " << marks << endl;
}

// Call by reference
void displayStudentInfo(const Student &student) {
    cout << "Student Name: " << student.name << endl;
    cout << "Marks: " << student.marks << endl;
    cout << "Grade: " << student.grade << endl;
}

// Call by reference
void calculateGrade(Student &student) {
    if (student.marks >= 90) {
        student.grade = 'A';
    } else if (student.marks >= 80) {
        student.grade = 'B';
    } else if (student.marks >= 70) {
        student.grade = 'C';
    } else if (student.marks >= 60) {
        student.grade = 'D';
    } else {
        student.grade = 'F';
    }
}
