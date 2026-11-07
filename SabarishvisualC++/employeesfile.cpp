#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Course {
    char code[10];
    char name[50];
    int credits;

public:
    void read() {
        cout << "Enter Course Code: ";
        cin >> code;
        cin.ignore();
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
};

int main() {
    fstream file;
    char opt;
    Course c;

    file.open("courses", ios::out | ios::binary);
    if (!file) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    do {
        cout << "\nEnter course details:\n";
        c.read();
        file.write((char*)&c, sizeof(c));
        cout << "Do you want to enter another course? (y/n): ";
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');
    file.close();

    file.open("courses", ios::in | ios::binary);
    if (!file) {
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

    while (file.read((char*)&c, sizeof(c))) {
        c.display();
    }

    file.close();
    return 0;
}
