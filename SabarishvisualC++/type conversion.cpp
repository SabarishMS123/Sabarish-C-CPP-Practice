#include <iostream>
using namespace std;

// Fahrenheit class (User-defined data type)
class F {
public:
    double temp;
    F(double t) { 
        temp = t; // Initialization inside the constructor body 
    }
};

// Conversion from Kelvin to Fahrenheit (Basic to User-defined)
F kToF(double k) {
    double f = (k - 273.15) * 9 / 5 + 32;
    return F(f);
}

// Celsius class (User-defined data type)
class C {
public:
    double temp;
    C(double t) {
        temp = t;
    }
};

// Conversion from Celsius to Calories (User-defined to Basic)
double cToCal(C c) {
    // Hypothetical conversion logic: Assume 1 Celsius = 1000 Calories (just an example)
    return c.temp * 1000;
}

int main() {
    // User input for Kelvin to Fahrenheit
    double k;
    cout << "Enter temperature in Kelvin: ";
    cin >> k;
    F fObj = kToF(k);
    cout << "The temperature " << k << " Kelvin is " << fObj.temp << " Fahrenheit." << endl;

    // User input for Celsius to Calories
    double c;
    cout << "Enter temperature in Celsius: ";
    cin >> c;
    C cObj(c);
    double cal = cToCal(cObj);
    cout << "The temperature " << cObj.temp << " Celsius is equivalent to " << cal << " Calories." << endl;

    return 0;
}
