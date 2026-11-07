#include <iostream>
#include <string>
using namespace std;

class Library {
private:
    string bTitles[100];
    string bAuthors[100];
    int tBooks;

public:
    Library() {
        tBooks = 0;
    }

    void addBook(string title, string author) {
        if (tBooks < 100) {
            bTitles[tBooks] = title;
            bAuthors[tBooks] = author;
            tBooks++;
        } else {
            cout << "Library is full!" << endl;
        }
    }

    void displayBooks() {
        cout << "Books in the Library:" << endl;
        for (int i = 0; i < tBooks; i++) {
            cout << i + 1 << ". " << bTitles[i] << " by " << bAuthors[i] << endl;
        }
    }

    int getTotalBooks() {
        return tBooks;
    }
};

int main() {
    Library l;
    int choice;
    string title, author;

    do {
        cout << "Library Menu:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Display books" << endl;
        cout << "3. Total number of books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore(); // To ignore the newline character left by cin
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                l.addBook(title, author);
                break;
            case 2:
                l.displayBooks();
                break;
            case 3:
                cout << "Total books: " << l.getTotalBooks() << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}