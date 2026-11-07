#include <iostream>
#include <cmath>

using namespace std;

// Function prototypes
double calculateCircleArea(double radius);
double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);
double calculateParallelogramArea(double base, double height);
double calculateTrapezoidArea(double base1, double base2, double height);
double calculateCombinedArea();

int main() {
    int choice;
    double area;

    cout << "Choose the shape of the land to calculate the area:" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;
    cout << "4. Parallelogram" << endl;
    cout << "5. Trapezoid" << endl;
    cout << "6. Combination of shapes" << endl;
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            area = calculateCircleArea(radius);
            break;
        }
        case 2: {
            double length, width;
            cout << "Enter the length and width of the rectangle: ";
            cin >> length >> width;
            area = calculateRectangleArea(length, width);
            break;
        }
        case 3: {
            double base, height;
            cout << "Enter the base and height of the triangle: ";
            cin >> base >> height;
            area = calculateTriangleArea(base, height);
            break;
        }
        case 4: {
            double base, height;
            cout << "Enter the base and height of the parallelogram: ";
            cin >> base >> height;
            area = calculateParallelogramArea(base, height);
            break;
        }
        case 5: {
            double base1, base2, height;
            cout << "Enter the lengths of the two bases and the height of the trapezoid: ";
            cin >> base1 >> base2 >> height;
            area = calculateTrapezoidArea(base1, base2, height);
            break;
        }
        case 6: {
            area = calculateCombinedArea();
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            return 1;
    }

    cout << "The area of the selected shape is: " << area << endl;
    return 0;
}

// Function to calculate the area of a circle
double calculateCircleArea(double radius) {
    return M_PI * radius * radius;
}

// Function to calculate the area of a rectangle
double calculateRectangleArea(double length, double width) {
    return length * width;
}

// Function to calculate the area of a triangle
double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

// Function to calculate the area of a parallelogram
double calculateParallelogramArea(double base, double height) {
    return base * height;
}

// Function to calculate the area of a trapezoid
double calculateTrapezoidArea(double base1, double base2, double height) {
    return 0.5 * (base1 + base2) * height;
}

// Function to calculate the area of a combination of shapes
double calculateCombinedArea() {
    double totalArea = 0.0;
    int numShapes;
    cout << "Enter the number of shapes in the combination: ";
    cin >> numShapes;

    for (int i = 0; i < numShapes; ++i) {
        int shapeChoice;
        cout << "Enter the shape type (1: Circle, 2: Rectangle, 3: Triangle, 4: Parallelogram, 5: Trapezoid): ";
        cin >> shapeChoice;

        switch (shapeChoice) {
            case 1: {
                double radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                totalArea += calculateCircleArea(radius);
                break;
            }
            case 2: {
                double length, width;
                cout << "Enter the length and width of the rectangle: ";
                cin >> length >> width;
                totalArea += calculateRectangleArea(length, width);
                break;
            }
            case 3: {
                double base, height;
                cout << "Enter the base and height of the triangle: ";
                cin >> base >> height;
                totalArea += calculateTriangleArea(base, height);
                break;
            }
            case 4: {
                double base, height;
                cout << "Enter the base and height of the parallelogram: ";
                cin >> base >> height;
                totalArea += calculateParallelogramArea(base, height);
                break;
            }
            case 5: {
                double base1, base2, height;
                cout << "Enter the lengths of the two bases and the height of the trapezoid: ";
                cin >> base1 >> base2 >> height;
                totalArea += calculateTrapezoidArea(base1, base2, height);
                break;
            }
            default:
                cout << "Invalid shape type!" << endl;
                --i; // Decrement the loop counter to retry the input
        }
    }

    return totalArea;
}
