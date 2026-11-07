#include <iostream>
#include <string>
using namespace std;

const int MAX_BOOKS = 100; // Maximum number of books the library can hold

// Structure to represent a book
struct Book {
    string title;
    bool isBorrowed;
};

// Function to display the menu
void displayMenu() {
    cout << "Library Management System\n";
    cout << "1. Add a book\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Display inventory\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function with default arguments to add a book
void addBook(Book books[], int &count, string title = "Unknown Book") { // Default Arguments
    if (count < MAX_BOOKS) {
        books[count] = {title, false};
        count++;
        cout << "Book added successfully.\n";
    } else {
        cout << "Library is full. Cannot add more books.\n";
    }
}

// Function to borrow a book (Call by Value)
void borrowBook(Book books[], int count, string title) { // Call by Value
    for (int i = 0; i < count; ++i) {
        if (books[i].title == title && !books[i].isBorrowed) {
            books[i].isBorrowed = true;
            cout << "Book borrowed successfully.\n";
            return;
        }
    }
    cout << "Book not found or already borrowed.\n";
}

// Function to return a book (Call by Address)
void returnBook(Book *books, int count, string title) { // Call by Address
    for (int i = 0; i < count; ++i) {
        if (books[i].title == title && books[i].isBorrowed) {
            books[i].isBorrowed = false;
            cout << "Book returned successfully.\n";
            return;
        }
    }
    cout << "Book not found or not borrowed.\n";
}

// Function to display inventory (Call by Reference)
void displayInventory(const Book (&books)[MAX_BOOKS], int count) { // Call by Reference
    cout << "\nCurrent Inventory:\n";
    for (int i = 0; i < count; ++i) {
        cout << "Title: " << books[i].title << ", Status: " << (books[i].isBorrowed ? "Borrowed" : "Available") << endl;
    }
    cout << endl;
}

// Function overloading to display a specific message
void displayInventory(const Book (&books)[MAX_BOOKS], int count, string message) { // Function Overloading
    cout << message << endl;
    displayInventory(books, count);
}

int main() {
    Book books[MAX_BOOKS];
    int count = 0; // Current number of books in the library
    int choice;
    string title;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: // Add a book
            cout << "Enter the title of the book (or press enter to use default): ";
            cin.ignore(); // To ignore any leftover newline character
            getline(cin, title);
            if (title.empty()) {
                addBook(books, count); // Uses default title
            } else {
                addBook(books, count, title);
            }
            break;
        case 2: // Borrow a book
            cout << "Enter the title of the book to borrow: ";
            cin.ignore();
            getline(cin, title);
            borrowBook(books, count, title);
            break;
        case 3: // Return a book
            cout << "Enter the title of the book to return: ";
            cin.ignore();
            getline(cin, title);
            returnBook(books, count, title);
            break;
        case 4: // Display inventory
            displayInventory(books, count, "Library Inventory:");
            break;
        case 5: // Exit
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

