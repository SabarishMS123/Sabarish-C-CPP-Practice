#include <iostream>
using namespace std;

void odd_Even_check(int number) {
    if (number % 2 == 0) {
        cout << "\n\tRESULT::\n\t";
        cout << "\n\t\t" << number << " is even.\n\n" << endl;
    } else {
        cout << "\n\tRESULT::\n\t";
        cout << "\n\t\t" << number << " is odd.\n\n" << endl;
    }
}

int main() {
    int n = 1;
    while (n != 0) {
        cout << "\n**** ODD OR EVEN INTEGER PROGRAM *****\n\t";
        cout << "Enter an integer: ";

        if (cin >> n) {
            if (n < 0) {
                cout << "\n\tRESULT::\n\t";
                cout << "\n\t YOU HAVE ENTERED A NEGATIVE NUMBER!!!\n\t";
                cout << "\n\nDo you want to alter the negative to positive and check for the ODD OR EVEN CONDITION? [1]YES [0]NO\n\t";
                int negn;
                cin >> negn;
                if (negn == 1) {
                    n *= -1;
                    odd_Even_check(n);
                }
            } else {
                odd_Even_check(n);
            }
        } else {
            // Clear the error flag on cin
            cin.clear();
            // Ignore the remaining input in the buffer
            char ch;
            cin >> ch;
            cout << "\n\tRESULT::\n\t";
            cout << "\n\t YOU HAVE ENTERED A CHARACTER!!!\n\t";
            cout << "\n\nDo you want to convert the character to its ASCII value and check for the ODD OR EVEN CONDITION? [1]YES [0]NO\n\t";
            int charCheck;
            cin >> charCheck;
            if (charCheck == 1) {
                int asciiValue = static_cast<int>(ch);
                cout << "\n\tThe ASCII value of '" << ch << "' is " << asciiValue << ".\n";
                odd_Even_check(asciiValue);
            }
        }

        cout << "Do you want to continue? [1]YES [0]NO\n\tEnter your choice:: ";
        cin >> n;
    }

    return 0;
}

