#include <iostream>
#include <string>
using namespace std;

class UserAuth {
private:
    string user;  
    string pass;  

public:
   
   UserAuth(const string& u, const string& p) 
   {
    user = u;
    pass = p;
}

    
    bool operator!=(const UserAuth& other) const {
        return user != other.user;  // Compare usernames
    }

    // Friend function to overload the == operator for password comparison
    friend bool operator==(const UserAuth& a, const UserAuth& b);
};

// Define the friend function for the == operator (password comparison)
bool operator==(const UserAuth& a, const UserAuth& b) {
    return a.pass == b.pass;  // Compare passwords
}

int main() {
    string uInp, pInp;  // User input for username and password

    // Predefined username and password
    UserAuth correctCred("admin", "1234");

    // Prompt the user to enter username and password
    cout << "Enter username: ";
    cin >> uInp;

    // Create a UserAuth object for the entered username (password is temporary here)
    UserAuth enteredCred(uInp, "");

    // Check if the username is incorrect
    if (enteredCred != correctCred) {
        cout << "Invalid username!" << endl;
    } else {
        // If username is correct, prompt for the password
        cout << "Enter password: ";
        cin >> pInp;

        // Update the entered credentials with the password
        enteredCred = UserAuth(uInp, pInp);

        // Check if the password is correct
        if (enteredCred == correctCred) {
            cout << "Access granted!" << endl;
        } else {
            cout << "Incorrect password!" << endl;
        }
    }

    return 0;
}
