#include <iostream>
#include <string>
using namespace std;

class UserAuth {
private:
    string username;  // Store the username
    string password;  // Store the password

public:
    // Constructor to initialize username and password
    UserAuth(const string& user, const string& pass) : username(user), password(pass) {}

    // Overload the != operator to compare username and password
    bool operator!=(const UserAuth& other) const {
        return (username != other.username) || (password != other.password);
    }

    // Method to display username and password (optional)
    void display() const {
        cout << "Username: " << username << ", Password: " << password << endl;
    }
};

int main() {
    string enteredUsername, enteredPassword;

    // Predefined username and password
    UserAuth correctCredentials("admin", "1234");

    // Prompt the user to enter username and password
    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    // Create UserAuth object for entered credentials
    UserAuth enteredCredentials(enteredUsername, enteredPassword);

    // Compare entered credentials with predefined credentials
    if (enteredCredentials != correctCredentials) {
        cout << "Invalid username or password!" << endl;
    } else {
        cout << "Access granted!" << endl;
    }

    return 0;
}
