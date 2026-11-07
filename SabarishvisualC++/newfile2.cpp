#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Patient {
    char id[10];
    char name[50];
    int age;
    char diagnosis[100];

public:
    void read() {
        cout << "Enter Patient ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Patient Name: ";
        cin.getline(name, 50);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Diagnosis: ";
        cin.getline(diagnosis, 100);
    }

    void display() {
        cout << setiosflags(ios::left) << setw(12) << id;
        cout << setw(30) << name;
        cout << setw(8) << age;
        cout << setw(40) << diagnosis << endl;
        cout << resetiosflags(ios::left);
    }
};

int main() {
    fstream file;
    char opt;
    Patient p;

    file.open("patients", ios::out | ios::binary);
    if (!file) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    do {
        cout << "\nEnter patient details:\n";
        p.read();
        file.write((char*)&p, sizeof(p));
        cout << "Do you want to enter another patient? (y/n): ";
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');
    file.close();

    file.open("patients", ios::in | ios::binary);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "\nPatient List:\n";
    cout << setiosflags(ios::left) << setw(12) << "ID"
         << setw(30) << "Name"
         << setw(8) << "Age"
         << setw(40) << "Diagnosis" << endl;
    cout << resetiosflags(ios::left);

    while (file.read((char*)&p, sizeof(p))) {
        p.display();
    }

    file.close();
    return 0;
}

