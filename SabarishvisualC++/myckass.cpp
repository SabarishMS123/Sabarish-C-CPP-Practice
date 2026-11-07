//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//class Book {
//private:
//    string title;
//    string author;
//    string isbn;
//    double price;
//    int copies;
//
//public:
//    // Method to initialize book details
//    void initializeBook() {
//        cout << "Enter title: ";
//        cin.ignore(); // Clear input buffer
//        getline(cin, title);
//        cout << "Enter author: ";
//        getline(cin, author);
//        cout << "Enter ISBN: ";
//        getline(cin, isbn);
//        cout << "Enter price: ";
//        cin >> price;
//        cout << "Enter number of copies: ";
//        cin >> copies;
//        cout << "Book initialized successfully.\n";
//    }
//
//    // Method to add more copies
//    void addCopies(int n) {
//        copies += n;
//        cout << n << " copies added. Total copies: " << copies << endl;
//    }
//
//    // Method to issue a book
//    void issueBook() {
//        if (copies > 0) {
//            copies--;
//            cout << "Book issued successfully. Remaining copies: " << copies << endl;
//        } else {
//            cout << "No copies available to issue.\n";
//        }
//    }
//
//    // Method to update the price
//    void setPrice(double new_price) {
//        price = new_price;
//        cout << "Price updated successfully to: " << price << endl;
//    }
//
//    // Method to display book details
//    void displayDetails() const {
//        cout << "\nBook Details:\n";
//        cout << "Title: " << title << endl;
//        cout << "Author: " << author << endl;
//        cout << "ISBN: " << isbn << endl;
//        cout << "Price: " << price << endl;
//        cout << "Available Copies: " << copies << endl;
//    }
//
//    // Method to search for a book by title
//    bool searchByTitle(const string& searchTitle) const {
//        return title == searchTitle;
//    }
//};
//
//// Main function
//int main() {
//    vector<Book> books; // To store multiple books
//    int choice;
//    int numBooks;
//    int bookIndex;
//    int copiesToAdd;
//    double newPrice;
//    string searchTitle;
//
//    cout << "Enter the number of books you want to initialize: ";
//    cin >> numBooks;
//
//    // Initialize all books
//    for (int i = 0; i < numBooks; i++) {
//        cout << "\nEnter details for Book " << i + 1 << ":\n";
//        Book newBook;
//        newBook.initializeBook();
//        books.push_back(newBook);
//    }
//
//    do {
//        cout << "\nMenu:\n";
//        cout << "1. Display Book Details\n";
//        cout << "2. Add Copies\n";
//        cout << "3. Issue Book\n";
//        cout << "4. Update Price\n";
//        cout << "5. Search by Title\n";
//        cout << "6. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            cout << "Enter the index of the book to display (1 to " << books.size() << "): ";
//            cin >> bookIndex;
//            if (bookIndex > 0 && bookIndex <= books.size()) {
//                books[bookIndex - 1].displayDetails();
//            } else {
//                cout << "Invalid index. Try again.\n";
//            }
//            break;
//        }
//        case 2: {
//            cout << "Enter the index of the book to add copies to (1 to " << books.size() << "): ";
//            cin >> bookIndex;
//            if (bookIndex > 0 && bookIndex <= books.size()) {
//                cout << "Enter number of copies to add: ";
//                cin >> copiesToAdd;
//                books[bookIndex - 1].addCopies(copiesToAdd);
//            } else {
//                cout << "Invalid index. Try again.\n";
//            }
//            break;
//        }
//        case 3: {
//            cout << "Enter the index of the book to issue (1 to " << books.size() << "): ";
//            cin >> bookIndex;
//            if (bookIndex > 0 && bookIndex <= books.size()) {
//                books[bookIndex - 1].issueBook();
//            } else {
//                cout << "Invalid index. Try again.\n";
//            }
//            break;
//        }
//        case 4: {
//            cout << "Enter the index of the book to update price (1 to " << books.size() << "): ";
//            cin >> bookIndex;
//            if (bookIndex > 0 && bookIndex <= books.size()) {
//                cout << "Enter new price: ";
//                cin >> newPrice;
//                books[bookIndex - 1].setPrice(newPrice);
//            } else {
//                cout << "Invalid index. Try again.\n";
//            }
//            break;
//        }
//        case 5: {
//            cin.ignore(); // Clear input buffer
//            cout << "Enter the title to search: ";
//            getline(cin, searchTitle);
//            bool found = false;
//            for (int i = 0; i < books.size(); i++) {
//                if (books[i].searchByTitle(searchTitle)) {
//                    cout << "Book found at index " << i + 1 << ":\n";
//                    books[i].displayDetails();
//                    found = true;
//                    break;
//                }
//            }
//            if (!found) {
//                cout << "Book not found.\n";
//            }
//            break;
//        }
//        case 6:
//            cout << "Exiting program. Thank you!\n";
//            break;
//        default:
//            cout << "Invalid choice. Please try again.\n";
//        }
//    } while (choice != 6);
//
//    return 0;
//}
#include <iostream>
#include <string>
using namespace std;

class MyString {
private:
    string str; // To store the string

public:
    // Function to set the string value
    void setString(const string& s) {
        str = s;
    }

    // Function to concatenate two strings
    MyString concatenate(const MyString& other)  {
        MyString result;
        result.str = str + other.str; // Concatenate strings
        return result;
    }

    // Function to display the string
    void display()  {
        cout << str << endl;
    }
};

int main() {
    MyString str1, str2, result;

    // Set values for the strings
    str1.setString("Hello, ");
    str2.setString("World!");

    // Concatenate strings
    result = str1.concatenate(str2);

    // Display the concatenated result
    result.display();

    return 0;
}

