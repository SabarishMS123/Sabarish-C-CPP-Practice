#include <iostream>
#include <cmath>  // For PI calculations
using namespace std;

const double PI = 3.1415926535;

template <typename T>
T calculateArea(string shape, T base, T height = 0) {
    if (shape == "parallelogram" || shape == "rectangle") {
        return base * height;
    } else if (shape == "triangle") {
        return 0.5 * base * height;
    } else if (shape == "trapezium") {
        T secondBase;
        cout << "Enter second base length: ";
        cin >> secondBase;
        return 0.5 * (base + secondBase) * height;
    } else if (shape == "circle") {
        return PI * base * base;  // Base represents radius
    } else if (shape == "ellipse") {
        T minorAxis;
        cout << "Enter minor axis length: ";
        cin >> minorAxis;
        return PI * base * minorAxis;  // Base represents major axis
    } else if (shape == "rhombus") {
        return 0.5 * base * height;  // Base and height are diagonals
    } else if (shape == "pentagon") {
        return (sqrt(5 * (5 + 2 * sqrt(5))) / 4) * base * base;  // Approximate formula using side length
    } else {
        cout << "Invalid shape!\n";
        return 0;
    }
}

int main() {
    string shape;
    double base, height;
    char choice;

    do {
        cout << "\nEnter shape (triangle / parallelogram / rectangle / trapezium / circle / ellipse / rhombus / pentagon): ";
        cin >> shape;
        cout << "Enter base length (or radius/side length): ";
        cin >> base;

        // Only ask for height if the shape requires it
        if (shape != "circle" && shape != "pentagon") {
            cout << "Enter height (or second axis/diagonal length): ";
            cin >> height;
        }

        double area = calculateArea(shape, base, height);
        cout << "The area of the " << shape << " is: " << area << " m² (" << area << " m^2)\n";

        cout << "\nDo you want to calculate another shape's area? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program terminated. Have a great day!\n";

    return 0;
}










