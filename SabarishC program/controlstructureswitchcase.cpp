#include <iostream>
#include <limits>
#include <string>
#include <sstream> // Include for stringstream

using namespace std;

char getGrade(double marks) {
    if (marks >= 90) return 'A';
    if (marks >= 80) return 'B';
    if (marks >= 70) return 'C';
    if (marks >= 60) return 'D';
    return 'F';
}

void printGradeStatus(char grade) {
    switch (grade) {
        case 'A': cout << "Excellent!"; break;
        case 'B': cout << "Good job!"; break;
        case 'C': cout << "Well done"; break;
        case 'D': cout << "You passed"; break;
        case 'F': cout << "Better try again"; break;
        default: cout << "Invalid grade"; break;
    }
}

string doubleToString(double value) {
    ostringstream strs;
    strs << value;
    return strs.str();
}

int main() {
    const int MAX_STUDENTS = 500;
    string name[MAX_STUDENTS], rollNo[MAX_STUDENTS], section[MAX_STUDENTS];
    double tamil[MAX_STUDENTS], english[MAX_STUDENTS], maths[MAX_STUDENTS], science[MAX_STUDENTS], socialScience[MAX_STUDENTS];
    int totalStudents = 0;
    char continueChoice;

    do {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer before reading each student's details

        cout << "\nEnter student's name: ";
        getline(cin, name[totalStudents]); // Use getline to read the entire name including spaces

        cout << "Enter roll number: ";
        getline(cin, rollNo[totalStudents]);

        cout << "Enter section: ";
        getline(cin, section[totalStudents]);

        double* subjects[] = { &tamil[totalStudents], &english[totalStudents], &maths[totalStudents], &science[totalStudents], &socialScience[totalStudents] };
        string subjectNames[] = { "Tamil", "English", "Maths", "Science", "Social Science" };

        for (int i = 0; i < 5; ++i) {
            int attempts = 0;
            do {
                if (attempts > 0) {
                    cout << "Invalid input! Marks cannot exceed 100. You have " << (3 - attempts) << " attempts left. Enter valid marks for " << subjectNames[i] << ": ";
                } else {
                    cout << "Enter marks for " << subjectNames[i] << " (out of 100): ";
                }
                cin >> *subjects[i];
                attempts++;
            } while ((*subjects[i] < 0 || *subjects[i] > 100) && attempts < 3);
            if (*subjects[i] < 0 || *subjects[i] > 100) {
                cout << "Failed to enter valid marks for " << subjectNames[i] << " after 3 attempts. Exiting.\n";
                return 1;
            }
        }

        totalStudents++;
        cout << "\nDo you want to continue? (y/n): ";
        cin >> continueChoice;
    } while ((continueChoice == 'y' || continueChoice == 'Y') && totalStudents < MAX_STUDENTS);

    // Final Report
    cout << "\n*** Overall Report ***\n";
    cout << "Name\tRoll No\tSection\tTamil\tStatus\tEnglish\tStatus\tMaths\tStatus\tScience\tStatus\tSocial Science\tStatus\tTotal\tAverage\tOverall Status\n";
    for (int i = 0; i < totalStudents; ++i) {
        double totalMarks = tamil[i] + english[i] + maths[i] + science[i] + socialScience[i];
        double averageMarks = totalMarks / 5;
        bool allPass = (getGrade(tamil[i]) != 'F' && getGrade(english[i]) != 'F' && getGrade(maths[i]) != 'F' && getGrade(science[i]) != 'F' && getGrade(socialScience[i]) != 'F');

        cout << name[i] << "\t" << rollNo[i] << "\t" << section[i] << "\t"
             << tamil[i] << "\t" << getGrade(tamil[i]) << "\t"
             << english[i] << "\t" << getGrade(english[i]) << "\t"
             << maths[i] << "\t" << getGrade(maths[i]) << "\t"
             << science[i] << "\t" << getGrade(science[i]) << "\t"
             << socialScience[i] << "\t" << getGrade(socialScience[i]) << "\t"
             << (allPass ? doubleToString(totalMarks) : "xxx") << "\t"
             << averageMarks << "\t"
             << (allPass ? "PASS" : "FAIL") << endl;
    }

    // Search Functionality
    string searchName;
    cout << "\nDo you want to search for a student? (y/n): ";
    cin >> continueChoice;
    if (continueChoice == 'y' || continueChoice == 'Y') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        cout << "Enter the name of the student: ";
        getline(cin, searchName);

        bool studentFound = false;
        for (int i = 0; i < totalStudents; ++i) {
            if (name[i] == searchName) {
                studentFound = true;
                cout << "\nHow do you want the details? (1 for horizontal, 2 for vertical): ";
                int displayChoice;
                cin >> displayChoice;

                double totalMarks = tamil[i] + english[i] + maths[i] + science[i] + socialScience[i];
                double averageMarks = totalMarks / 5;
                bool allPass = (getGrade(tamil[i]) != 'F' && getGrade(english[i]) != 'F' && getGrade(maths[i]) != 'F' && getGrade(science[i]) != 'F' && getGrade(socialScience[i]) != 'F');

                if (displayChoice == 1) { // Horizontal
                    cout << "\nName\tRoll No\tTamil\tStatus\tEnglish\tStatus\tMaths\tStatus\tScience\tStatus\tSocial Science\tStatus\tTotal\tAverage\tOverall Status\n";
                    cout << name[i] << "\t" << rollNo[i] << "\t"
                         << tamil[i] << "\t" << getGrade(tamil[i]) << "\t"
                         << english[i] << "\t" << getGrade(english[i]) << "\t"
                         << maths[i] << "\t" << getGrade(maths[i]) << "\t"
                         << science[i] << "\t" << getGrade(science[i]) << "\t"
                         << socialScience[i] << "\t" << getGrade(socialScience[i]) << "\t"
                         << (allPass ? doubleToString(totalMarks) : "xxx") << "\t"
                         << averageMarks << "\t"
                         << (allPass ? "PASS" : "FAIL") << endl;
                } else if (displayChoice == 2) { // Vertical
                    cout << "\nName: " << name[i] << endl;
                    cout << "Roll No: " << rollNo[i] << endl;
                    cout << "Tamil: " << tamil[i] << " Status: " << getGrade(tamil[i]) << endl;
                    cout << "English: " << english[i] << " Status: " << getGrade(english[i]) << endl;
                    cout << "Maths: " << maths[i] << " Status: " << getGrade(maths[i]) << endl;
                    cout << "Science: " << science[i] << " Status: " << getGrade(science[i]) << endl;
                    cout << "Social: " << socialScience[i] << " Status: " << getGrade(socialScience[i]) << endl;
                    cout << "Total: " << (allPass ? doubleToString(totalMarks) : "xxx") << endl;
                    cout << "Average: " << averageMarks << endl;
                    cout << "Overall Status: " << (allPass ? "PASS" : "FAIL") << endl;
                }
            }
        }
        if (!studentFound) {
            cout << "Student not found.\n";
        }
    }

    return 0;
}

