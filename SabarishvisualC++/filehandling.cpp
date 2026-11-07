//#include <iostream>
//#include <fstream>
//#include <iomanip>
//using namespace std;
//
//class Course {
//    char code[10];
//    char name[50];
//    int credits;
//
//public:
//    void read() {
//        cout << "Enter Course Code: ";
//        cin >> code;
//        cin.ignore();
//        cout << "Enter Course Name: ";
//        cin.getline(name, 50);
//        cout << "Enter Credits: ";
//        cin >> credits;
//    }
//
//    void display() {
//        cout << setiosflags(ios::left) << setw(12) << code;
//        cout << setw(30) << name;
//        cout << resetiosflags(ios::left);
//        cout << setiosflags(ios::right);
//        cout << setw(8) << credits << endl;
//        cout << resetiosflags(ios::right);
//    }
//};
//
//int main() {
//    fstream file;
//    char opt;
//    Course c;
//
//    file.open("courses", ios::out | ios::binary);
//    if (!file) {
//        cout << "Error creating file!" << endl;
//        return 1;
//    }
//
//    do {
//        cout << "\nEnter course details:\n";
//        c.read();
//        file.write((char*)&c, sizeof(c));
//        cout << "Do you want to enter another course? (y/n): ";
//        cin >> opt;
//    } while (opt == 'y' || opt == 'Y');
//    file.close();
//
//    file.open("courses", ios::in | ios::binary);
//    if (!file) {
//        cout << "Error opening file!" << endl;
//        return 1;
//    }
//
//    cout << "\nCourse List:\n";
//    cout << setiosflags(ios::left) << setw(12) << "Code"
//         << setw(30) << "Name"
//         << resetiosflags(ios::left)
//         << setiosflags(ios::right)
//         << setw(8) << "Credits" << endl;
//    cout << resetiosflags(ios::right);
//
//    while (file.read((char*)&c, sizeof(c))) {
//        c.display();
//    }
//
//    file.close();
//    return 0;
//}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Course {
public:
    char code[10];
    char name[50];
    int credits;

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
        cout << setiosflags(ios::left) << setw(12) << code
             << setiosflags(ios::left) << setw(30) << name
             << setiosflags(ios::right) << setw(8) << credits << endl;
    }
};

int main() {
    fstream file("courses", ios::in | ios::out | ios::binary);
    Course c;
    int opt;

    if (!file) {
        file.open("courses", ios::out | ios::binary);
        if (!file) {
            cout << "Error creating file!" << endl;
            return 1;
        }
        file.close();
        file.open("courses", ios::in | ios::out | ios::binary);
    }

    while (true) {
        cout << "\n1 - Display number of courses\n";
        cout << "2 - Display a particular course\n";
        cout << "3 - Update a particular course\n";
        cout << "4 - Add a new course\n";
        cout << "5 - Exit\n";
        cout << "Enter your option: ";
        cin >> opt;

        file.clear();
        file.seekg(0, ios::end);
        int filesize = file.tellg();
        int objsize = sizeof(Course);
        int n = filesize / objsize;

        switch (opt) {
            case 1:
                cout << "Number of courses in the file: " << n << endl;
                break;

            case 2: {
                int num;
                cout << "Enter course number to display (1 to " << n << "): ";
                cin >> num;
                if (num < 1 || num > n) {
                    cout << "Invalid course number!\n";
                    break;
                }
                file.seekg((num - 1) * objsize, ios::beg);
                file.read((char*)&c, sizeof(c));

                cout << setiosflags(ios::left) << setw(12) << "Code"
                     << setiosflags(ios::left) << setw(30) << "Name"
                     << setiosflags(ios::right) << setw(8) << "Credits" << endl;
                cout << "-----------------------------------------------------\n";
                c.display();
                break;
            }

            case 3: {
                int num;
                cout << "Enter course number to update (1 to " << n << "): ";
                cin >> num;
                if (num < 1 || num > n) {
                    cout << "Invalid course number!\n";
                    break;
                }
                cout << "Enter new course details:\n";
                c.read();
                file.seekp((num - 1) * objsize, ios::beg);
                file.write((char*)&c, sizeof(c));
                file.flush();
                cout << "Course updated successfully.\n";
                break;
            }

            case 4:
                cout << "Enter new course details:\n";
                c.read();
                file.clear();
                file.seekp(0, ios::end);
                file.write((char*)&c, sizeof(c));
                file.flush();
                cout << "Course added successfully.\n";
                break;

            case 5:
                cout << "Exiting...\n";
                file.close();
                return 0;

            default:
                cout << "Invalid option!\n";
        }
    }
}
