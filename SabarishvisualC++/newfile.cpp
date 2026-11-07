#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits> // Required for numeric_limits

using namespace std;

class Course {
    char code[10];
    char name[50];
    int credits;

public:
    void read() {
        cout << "Enter Course Code: ";
        cin >> code;
        // Clear the buffer after reading an integer/string to prepare for getline
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Enter Course Name: ";
        cin.getline(name, 50);
        cout << "Enter Credits: ";
        cin >> credits;
    }

    void display() {
        cout << setiosflags(ios::left) << setw(12) << code;
        cout << setw(30) << name;
        cout << resetiosflags(ios::left);
        cout << setiosflags(ios::right);
        cout << setw(8) << credits << endl;
        cout << resetiosflags(ios::right);
    }

    // Function to write course data to a text file
    void writeToFile(ofstream& outFile) {
        outFile << code << endl;
        outFile << name << endl;
        outFile << credits << endl;
    }

    // Function to read course data from a text file
    void readFromFile(ifstream& inFile) {
        inFile.getline(code, 10);
        inFile.getline(name, 50);
        inFile >> credits;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n'); // Consume the newline after reading credits
    }
};

int main() {
    char opt;
    Course c;

    // --- Writing to Text File ---
    ofstream outFile("courses.txt"); // Open for writing (creates/truncates file)
    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    do {
        cout << "\nEnter course details:\n";
        c.read();
        c.writeToFile(outFile); // Write to text file
        cout << "Do you want to enter another course? (y/n): ";
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');
    outFile.close();

    // --- Reading from Text File ---
    ifstream inFile("courses.txt"); // Open for reading
    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "\nCourse List:\n";
    cout << setiosflags(ios::left) << setw(12) << "Code"
         << setw(30) << "Name"
         << resetiosflags(ios::left)
         << setiosflags(ios::right)
         << setw(8) << "Credits" << endl;
    cout << resetiosflags(ios::right);

    // Read until end of file
    while (inFile.peek() != EOF) { // Check for end of file before attempting to read
        c.readFromFile(inFile); // Read from text file
        c.display();
    }

    inFile.close();
    return 0;
}