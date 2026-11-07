#include <iostream>
#include <fstream>

using namespace std;

void copyFile(const string& sourceFile, const string& destinationFile, ios::openmode mode) {
    ifstream inFile(sourceFile, mode);
    ofstream outFile(destinationFile, mode);

    if (!inFile || !outFile) {
        cerr << "Error opening files!" << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)) { // Read character-by-character
        outFile.put(ch); // Write character-by-character
    }

    cout << "File copied successfully from " << sourceFile << " to " << destinationFile << endl;
    
    inFile.close();
    outFile.close();
}

int main() {
    string sourceFile, destinationFile;
    char fileType;

    cout << "Enter the source filename: ";
    cin >> sourceFile;

    cout << "Enter the destination filename: ";
    cin >> destinationFile;

    cout << "Is this a binary file? (y/n): ";
    cin >> fileType;

    if (fileType == 'y' || fileType == 'Y') {
        copyFile(sourceFile, destinationFile, ios::binary);
    } else {
        copyFile(sourceFile, destinationFile, ios::in);
    }

    return 0;
}