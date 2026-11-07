//#include <iostream>  // Required for input/output operations (cin, cout)
//#include <fstream>   // Required for file stream operations (fstream)
//#include <iomanip>   // Required for output formatting (setw, setiosflags, resetiosflags)
//#include <string>    // Required for string manipulation, though char arrays are used here
//
//// Define the Patient class to store patient information
//class Patient {
//    char tokenNumber[10]; // Character array to store patient Token Number (e.g., "T001")
//    char name[50];        // Character array to store patient name
//    int age;              // Integer to store patient age
//
//public:
//    // Method to read patient details from the console
//    void read() {
//        std::cout << "Enter Patient Token Number: ";
//        std::cin >> tokenNumber; // Read patient Token Number
//        std::cin.ignore();       // Consume the newline character left by cin >> tokenNumber
//        std::cout << "Enter Patient Name: ";
//        std::cin.getline(name, 50); // Read patient name, allowing spaces
//        std::cout << "Enter Patient Age: ";
//        std::cin >> age; // Read patient age
//    }
//
//    // Method to display patient details to the console in a formatted way
//    void display() {
//        // Set left alignment for Token Number and Name, and specify width
//        std::cout << std::setiosflags(std::ios::left) << std::setw(12) << tokenNumber;
//        std::cout << std::setw(30) << name;
//        // Reset left alignment for subsequent output
//        std::cout << std::resetiosflags(std::ios::left);
//
//        // Set right alignment for Age and specify width
//        std::cout << std::setiosflags(std::ios::right);
//        std::cout << std::setw(8) << age << std::endl;
//        // Reset right alignment for subsequent output
//        std::cout << std::resetiosflags(std::ios::right);
//    }
//};
//
//// Main function where the program execution begins
//int main() {
//    std::fstream file; // Declare an fstream object for file operations
//    char opt;           // Character variable to store user's choice (y/n)
//    Patient p;          // Create an object of the Patient class
//
//    // Open the file named "patients" in output mode (ios::out) and binary mode (ios::binary)
//    // If the file doesn't exist, it will be created. If it exists, its content will be truncated.
//    file.open("patients", std::ios::out | std::ios::binary);
//    // Check if the file was opened successfully
//    if (!file) {
//        std::cout << "Error creating file 'patients'!" << std::endl;
//        return 1; // Return 1 to indicate an error
//    }
//
//    // Loop to continuously ask for patient details until the user decides to stop
//    do {
//        std::cout << "\nEnter patient details:\n";
//        p.read(); // Call the read method of the Patient object to get input
//        // Write the entire Patient object (its raw binary data) to the file
//        // (char*)&p casts the address of the object to a char pointer
//        // sizeof(p) gets the size of the Patient object in bytes
//        file.write(reinterpret_cast<char*>(&p), sizeof(p));
//        std::cout << "Do you want to enter another patient? (y/n): ";
//        std::cin >> opt; // Read user's choice
//    } while (opt == 'y' || opt == 'Y'); // Continue if user enters 'y' or 'Y'
//    file.close(); // Close the file after writing all data
//
//    // Open the file named "patients" in input mode (ios::in) and binary mode (ios::binary)
//    file.open("patients", std::ios::in | std::ios::binary);
//    // Check if the file was opened successfully
//    if (!file) {
//        std::cout << "Error opening file 'patients'!" << std::endl;
//        return 1; // Return 1 to indicate an error
//    }
//
//    std::cout << "\nPatient List:\n";
//    // Print table headers with appropriate formatting
//    std::cout << std::setiosflags(std::ios::left) << std::setw(12) << "Token No." // Updated header
//              << std::setw(30) << "Name"
//              << std::resetiosflags(std::ios::left)
//              << std::setiosflags(std::ios::right)
//              << std::setw(8) << "Age" << std::endl;
//    std::cout << std::resetiosflags(std::ios::right);
//
//    // Loop to read patient records from the file until the end of the file is reached
//    while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
//        p.display(); // Call the display method of the Patient object to show details
//    }
//
//    file.close(); // Close the file after reading all data
//    return 0;     // Return 0 to indicate successful program execution
//}

#include <iostream>  // Required for input/output operations (cin, cout)
#include <fstream>   // Required for file stream operations (fstream)
#include <iomanip>   // Required for output formatting (setw, setiosflags, resetiosflags)
#include <cstring>   // Required for string manipulation functions like strcpy (though not explicitly used here, good practice for char arrays)

// Define the Patient class to store patient information
class Patient {
public: // Made public for direct access in main, similar to the Course example
    char tokenNumber[10]; // Character array to store patient Token Number (e.g., "T001")
    char name[50];        // Character array to store patient name
    int age;              // Integer to store patient age

    // Method to read patient details from the console
    void read() {
        std::cout << "Enter Patient Token Number: ";
        std::cin >> tokenNumber; // Read patient Token Number
        // Clear the input buffer to consume the newline character left by std::cin >> tokenNumber
        std::cin.ignore();
        std::cout << "Enter Patient Name: ";
        // Read patient name, allowing spaces, up to 49 characters + null terminator
        std::cin.getline(name, 50);
        std::cout << "Enter Patient Age: ";
        std::cin >> age; // Read patient age
    }

    // Method to display patient details to the console in a formatted way
    void display() {
        // Set left alignment for Token Number and Name, and specify width
        std::cout << std::setiosflags(std::ios::left) << std::setw(12) << tokenNumber
                  << std::setiosflags(std::ios::left) << std::setw(30) << name
                  // Set right alignment for Age and specify width
                  << std::setiosflags(std::ios::right) << std::setw(8) << age << std::endl;
        // The flags are reset implicitly by subsequent setiosflags or explicitly by resetiosflags if needed
    }
};

// Main function where the program execution begins
int main() {
    // Open the file named "patients" in input, output, and binary mode.
    // This allows both reading and writing to the same file.
    std::fstream file("patients", std::ios::in | std::ios::out | std::ios::binary);
    Patient p; // Create an object of the Patient class
    int opt;   // Integer variable to store user's menu option

    // Check if the file failed to open initially (e.g., it doesn't exist)
    if (!file) {
        // If it failed, try to create it in output mode
        file.open("patients", std::ios::out | std::ios::binary);
        if (!file) {
            std::cout << "Error creating file 'patients'!" << std::endl;
            return 1; // Return 1 to indicate an error
        }
        file.close(); // Close the newly created file
        // Reopen the file in input, output, and binary mode for normal operation
        file.open("patients", std::ios::in | std::ios::out | std::ios::binary);
    }

    // Main program loop for the menu
    while (true) {
        std::cout << "\n--- Patient Management System ---\n";
        std::cout << "1 - Display number of patients\n";
        std::cout << "2 - Display a particular patient\n";
        std::cout << "3 - Update a particular patient\n";
        std::cout << "4 - Add a new patient\n";
        std::cout << "5 - Exit\n";
        std::cout << "Enter your option: ";
        std::cin >> opt; // Read user's menu choice

        // Clear any error flags on the file stream, which might have been set by previous operations
        // (e.g., reaching end-of-file during a read). This is crucial before seeking.
        file.clear();
        // Move the file pointer to the end of the file to determine its size
        file.seekg(0, std::ios::end);
        // Get the current position of the file pointer, which represents the file size in bytes
        int filesize = file.tellg();
        // Get the size of a single Patient object
        int objsize = sizeof(Patient);
        // Calculate the number of Patient records in the file
        int n = filesize / objsize;

        // Use a switch statement to handle different menu options
        switch (opt) {
            case 1: // Display number of patients
                std::cout << "Number of patients in the file: " << n << std::endl;
                break;

            case 2: { // Display a particular patient
                int num;
                std::cout << "Enter patient number to display (1 to " << n << "): ";
                std::cin >> num; // Read the patient number from the user
                // Validate the input patient number
                if (num < 1 || num > n) {
                    std::cout << "Invalid patient number!\n";
                    break; // Exit case 2
                }
                // Move the file pointer to the beginning of the desired patient record
                // (num - 1) because file records are 0-indexed while user input is 1-indexed
                file.seekg((num - 1) * objsize, std::ios::beg);
                // Read the patient record from the file into the 'p' object
                file.read(reinterpret_cast<char*>(&p), sizeof(p));

                // Print table headers for display
                std::cout << "\n-----------------------------------------------------\n";
                std::cout << std::setiosflags(std::ios::left) << std::setw(12) << "Token No."
                          << std::setiosflags(std::ios::left) << std::setw(30) << "Name"
                          << std::setiosflags(std::ios::right) << std::setw(8) << "Age" << std::endl;
                std::cout << "-----------------------------------------------------\n";
                p.display(); // Display the retrieved patient details
                std::cout << "-----------------------------------------------------\n";
                break;
            }

            case 3: { // Update a particular patient
                int num;
                std::cout << "Enter patient number to update (1 to " << n << "): ";
                std::cin >> num; // Read the patient number to update
                // Validate the input patient number
                if (num < 1 || num > n) {
                    std::cout << "Invalid patient number!\n";
                    break; // Exit case 3
                }
                std::cout << "Enter new patient details:\n";
                // Read the new details for the patient
                p.read();
                // Move the file pointer to the beginning of the desired patient record for writing
                file.seekp((num - 1) * objsize, std::ios::beg);
                // Write the updated patient object to the file
                file.write(reinterpret_cast<char*>(&p), sizeof(p));
                // Ensure all buffered output is written to the file immediately
                file.flush();
                std::cout << "Patient updated successfully.\n";
                break;
            }

            case 4: // Add a new patient
                std::cout << "Enter new patient details:\n";
                p.read(); // Read details for the new patient
                // Clear any error flags on the file stream before seeking
                file.clear();
                // Move the file pointer to the end of the file for appending
                file.seekp(0, std::ios::end);
                // Write the new patient object to the end of the file
                file.write(reinterpret_cast<char*>(&p), sizeof(p));
                // Ensure all buffered output is written to the file immediately
                file.flush();
                std::cout << "Patient added successfully.\n";
                break;

            case 5: // Exit the program
                std::cout << "Exiting...\n";
                file.close(); // Close the file before exiting
                return 0;     // Return 0 to indicate successful program termination

            default: // Handle invalid menu options
                std::cout << "Invalid option! Please try again.\n";
        }
    }
}

