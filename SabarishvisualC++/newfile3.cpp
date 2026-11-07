#include <iostream>   // For input/output operations (cout, cin)
#include <fstream>    // For file stream operations (fstream)
#include <iomanip>    // For output formatting (setw, setiosflags, resetiosflags)
#include <cstring>    // For string manipulation functions (though not strictly needed for char arrays with cin.getline)

using namespace std;

// Define a class to represent a Patient
class Patient {
public:
    char id[10];      // Character array for Patient ID (e.g., "P001")
    char name[50];    // Character array for Patient Name
    int age;          // Integer for Patient Age
    char diagnosis[100]; // Character array for Patient Diagnosis

    // Function to read patient details from user input
    void read() {
        cout << "Enter Patient ID: ";
        cin >> id; // Read patient ID
        cin.ignore(); // Consume the newline character left by cin >> id
        cout << "Enter Patient Name: ";
        cin.getline(name, 50); // Read patient name, including spaces
        cout << "Enter Age: ";
        cin >> age; // Read age
        cin.ignore(); // Consume the newline character left by cin >> age
        cout << "Enter Diagnosis: ";
        cin.getline(diagnosis, 100); // Read diagnosis, including spaces
    }

    // Function to display patient details in a formatted way
    void display() {
        // Use setiosflags(ios::left) to left-align output for most fields
        // Use setw() to set the width for each field
        cout << setiosflags(ios::left) << setw(12) << id
             << setiosflags(ios::left) << setw(30) << name
             << setiosflags(ios::right) << setw(8) << age // Right-align age for numerical clarity
             << setiosflags(ios::left) << setw(40) << diagnosis << endl;
        cout << resetiosflags(ios::left); // Reset left-alignment flag
    }
};

int main() {
    // Open the file "patients" in input, output, and binary modes.
    // If the file doesn't exist, it will be created.
    fstream file;
    file.open("patients", ios::in | ios::out | ios::binary);

    // If the file doesn't exist or can't be opened for both read/write,
    // try to create it first, then reopen. This handles initial creation.
    if (!file.is_open()) {
        file.clear(); // Clear any error flags if it failed to open
        file.open("patients", ios::out | ios::binary); // Try to create it (truncates if exists)
        if (!file.is_open()) {
            cout << "Error creating file 'patients'!" << endl;
            return 1; // Exit with an error code
        }
        file.close(); // Close the newly created file
        // Reopen in desired read/write mode
        file.open("patients", ios::in | ios::out | ios::binary);
        if (!file.is_open()) {
            cout << "Error opening file 'patients' after creation!" << endl;
            return 1;
        }
    }

    Patient p; // Create a Patient object
    int opt;   // Variable to store user's menu option

    // Main program loop for menu interaction
    while (true) {
        // Clear any error flags on the file stream (e.g., EOF from previous reads)
        // This is crucial before seeking or checking file size.
        file.clear();
        // Move the file pointer to the end of the file to determine its size
        file.seekg(0, ios::end);
        int filesize = file.tellg(); // Get the current position (which is the file size)
        int objsize = sizeof(Patient); // Get the size of one Patient object
        int n = 0; // Initialize number of patients
        if (objsize > 0) { // Prevent division by zero if Patient size is somehow 0
            n = filesize / objsize; // Calculate the number of Patient objects in the file
        }

        // Display menu options to the user
        cout << "\n--- Patient Management System (Random Access) ---\n";
        cout << "1 - Display number of patients\n";
        cout << "2 - Display a particular patient\n";
        cout << "3 - Update a particular patient\n";
        cout << "4 - Add a new patient\n";
        cout << "5 - Display ALL patients\n";
        cout << "6 - Exit\n";
        cout << "Enter your option: ";
        cin >> opt; // Read user's option


        // Use a switch statement to handle different menu options
        switch (opt) {
            case 1: // Display number of patients
                cout << "Number of patients in the file: " << n << endl;
                break;

            case 2: { // Display a particular patient
                int num;
                cout << "Enter patient number to display (1 to " << n << "): ";
                cin >> num;
                if (num < 1 || num > n) {
                    cout << "Invalid patient number!\n";
                    break;
                }
                // Seek to the beginning of the desired record
                file.seekg((num - 1) * objsize, ios::beg);
                file.read((char*)&p, sizeof(p)); // Read the patient object

                // Display header for the patient details
                cout << setiosflags(ios::left) << setw(12) << "ID"
                     << setiosflags(ios::left) << setw(30) << "Name"
                     << setiosflags(ios::right) << setw(8) << "Age"
                     << setiosflags(ios::left) << setw(40) << "Diagnosis" << endl;
                cout << "-----------------------------------------------------------------------------------\n";
                p.display(); // Display the patient details
                break;
            }

            case 3: { // Update a particular patient
                int num;
                cout << "Enter patient number to update (1 to " << n << "): ";
                cin >> num;
                if (num < 1 || num > n) {
                    cout << "Invalid patient number!\n";
                    break;
                }
                cout << "Enter new patient details:\n";
                p.read(); // Read new details for the patient
                // Seek to the beginning of the desired record for writing
                file.seekp((num - 1) * objsize, ios::beg);
                file.write((char*)&p, sizeof(p)); // Write the updated patient object
                file.flush(); // Ensure data is written to disk immediately
                cout << "Patient updated successfully.\n";
                break;
            }

            case 4: // Add a new patient
                cout << "Enter new patient details:\n";
                p.read(); // Read details for the new patient
                file.clear(); // Clear any error flags before seeking to end for appending
                file.seekp(0, ios::end); // Move write pointer to the end of the file
                file.write((char*)&p, sizeof(p)); // Write the new patient object
                file.flush(); // Ensure data is written to disk immediately
                cout << "Patient added successfully.\n";
                break;

            case 5: { // Display ALL patients
                if (n == 0) {
                    cout << "No patients found in the file.\n";
                    break;
                }
                // Display header for the patient list
                cout << "\n--- All Patients ---\n";
                cout << setiosflags(ios::left) << setw(12) << "ID"
                     << setiosflags(ios::left) << setw(30) << "Name"
                     << setiosflags(ios::right) << setw(8) << "Age"
                     << setiosflags(ios::left) << setw(40) << "Diagnosis" << endl;
                cout << "-----------------------------------------------------------------------------------\n";

                file.clear(); // Clear any error flags
                file.seekg(0, ios::beg); // Move read pointer to the beginning of the file

                // Read and display each patient until the end of the file is reached
                while (file.read((char*)&p, sizeof(p))) {
                    p.display();
                }
                break;
            }

            case 6: // Exit the program
                cout << "Exiting...\n";
                file.close(); // Close the file before exiting
                return 0; // Exit successfully

            default: // Handle invalid menu options
                cout << "Invalid option! Please try again.\n";
        }
    }
}

