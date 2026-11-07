#include <iostream>
#include <fstream>

using namespace std;

int main() {
    char ch;
    char str[50];

    // Using get() to read a single character
    cout << "Enter a character: ";
    cin.get(ch);
    cout << "You entered: ";
    cout.put(ch);
    cout << endl;

    // Clearing input buffer
    cin.ignore();

    // Using getline() to read a line
    cout << "Enter a string: ";
    cin.getline(str, 50);
    cout << "You entered: " << str << endl;

    // Using read() to read raw data from a file
    ifstream infile("sample.txt", ios::in);
    if (infile) {
        infile.read(str, 20); // Reads first 20 characters
        str[infile.gcount()] = '\0'; // Null-terminate the string
        cout << "Contents from file: " << str << endl;
        infile.close();
    } else {
        cout << "Failed to open file." << endl;
    }

    // Using write() to write raw data to a file
    ofstream outfile("output.txt", ios::out);
    if (outfile) {
        outfile.write(str, 20);
        cout << "Data written to output.txt" << endl;
        outfile.close();
    } else {
        cout << "Failed to write to file." << endl;
    }

    return 0;
}