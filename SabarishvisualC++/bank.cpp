#include<iostream>
using namespace std;


int amt = 500;

// 1. With arg, without return
void deposit(int d) {
    amt = amt + d; 
    cout << "\nAmount deposited. New balance: $" << amt << endl;
}

// 2. Without arg, without return
void showmenu() {
    cout << "\n--- Menu ---";
    cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit";
    cout << "\nEnter choice: ";
}

// 3. Without arg, with return 
// Without argument, with return
int withdraw() {
    int w;
    cout << "Enter amount to withdraw: ";
    cin >> w;
    
    // We use the global 'amt' or a calculation
    int remaining = amt - w; 
    
    cout << "Withdrawing... ";
    return remaining; // This sends the result back to main
}

// 4. With arg, with return
int checkbalance(int currentAmt) {
    return currentAmt;
}

void exi() {
    cout << "Exited system." << endl;
}

int main() {
    string uname;
    int pass, choice, t = 2;

    cout << "Enter the name: ";
    cin >> uname;

    do {
        cout << "\nEnter the password: ";
        cin >> pass;

        if (pass == 12345) {
            showmenu();
            cin >> choice;

            if (choice == 1) {
                int d;
                cout << "Enter deposit amt: "; 
                cin >> d;
                deposit(d);
            }
            else if (choice == 2) {
                withdraw();
            }
            else if (choice == 3) {
                cout << "Current Balance: $" << checkbalance(amt) << endl;
            }
            else {
                exi();
                return 0; // End the program
            }
        }
        else {
            cout << "Wrong password! Attempts left: " << t << endl;
            t--;
        }

    } while (t >= 0);

    if (t == -1) {
        cout << "\nYour account has been blocked." << endl;
    }

    return 0;
}
