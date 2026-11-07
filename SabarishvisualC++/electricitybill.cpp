#include <iostream>
#include <string>
using namespace std;

class Customer {
    int custNum;
    string name;
    int units;
    double bill;

public:
    void getDetails() {
        cout << "Cust No: ";
        cin >> custNum;
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Units used: ";
        cin >> units;
    }

    void calcBill() {
        
        bill = (units <= 100) ? 0 :
       (units <= 200) ? (units - 100) * 2.25 :
       (units <= 400) ? 100 * 2.25 + (units - 200) * 4.5 :
       (units <= 500) ? 100 * 2.25 + 200 * 4.5 + (units - 400) * 6 :
       (units <= 600) ? 300 * 4.5 + 100 * 6 + (units - 500) * 8 :
       (units <= 800) ? 300 * 4.5 + 100 * 6 + 100 * 8 + (units - 600) * 9 :
       (units <= 1000) ? 300 * 4.5 + 100 * 6 + 100 * 8 + 200 * 9 + (units - 800) * 10 :
       300 * 4.5 + 100 * 6 + 100 * 8 + 200 * 9 + 200 * 10 + (units - 1000) * 11;

    }

    void showDetails() {
        cout << "\nCust No: " << custNum;
        cout << "\nName: " << name;
        cout << "\nUnits: " << units;
        cout << "\nBill: Rs. " << bill << endl;
    }
};

int main() {
    Customer c;
    c.getDetails();
    c.calcBill();
    c.showDetails();
    return 0;
}
