#include <iostream>
#include <string>
#include <cmath> // For abs()
using namespace std;

class Vehicle {
private:
    string vName;
    double fuel;
    double dist;
    double emiFactor;
    double eff;

public:
    // Default Constructor
    Vehicle() {
        vName = "Unknown Vehicle";
        fuel = 0;
        dist = 0;
        emiFactor = 2.31;
        eff = 0;
        cout << "Default Constructor: Vehicle initialized with default values.\n";
    }

    // Parameterized Constructor
    Vehicle(const string& name, double f, double d, double eFactor) {
        vName = name;
        fuel = f;
        dist = d;
        emiFactor = eFactor;
        eff = calculateEfficiency();
        cout << "Parameterized Constructor: Vehicle '" << vName << "' initialized.\n";
    }

    // Copy Constructor
    Vehicle(const Vehicle& other) {
        vName = other.vName;
        fuel = other.fuel;
        dist = other.dist;
        emiFactor = other.emiFactor;
        eff = other.eff;
        cout << "Copy Constructor: Vehicle '" << vName << "' copied.\n";
    }

    // Method to calculate mileage
    double calculateMileage() const {
        return (fuel == 0) ? 0 : dist / fuel;
    }

    // Method to calculate emissions
    double calculateEmissions() const {
        return fuel * emiFactor * 1000;
    }

    // Method to calculate efficiency
    double calculateEfficiency() const {
        return (dist == 0 || fuel == 0) ? 0 : (calculateMileage() / 20.0) * 100;
    }

    // Method to display vehicle details
    void displayDetails() const {
        cout << "Vehicle Name: " << vName << endl;
        cout << "Fuel Consumed: " << fuel << " liters\n";
        cout << "Distance Traveled: " << dist << " km\n";
        cout << "Mileage: " << calculateMileage() << " km/l\n";
        cout << "Carbon Emissions: " << calculateEmissions() << " grams\n";
        cout << "Engine Efficiency: " << eff << " %\n";
    }

    // Method to compare the current vehicle with another
    void compareWith(const Vehicle& other) const {
        cout << "Comparing '" << vName << "' with '" << other.vName << "':\n";
        cout << "Fuel Consumed Difference: " << abs(fuel - other.fuel) << " liters\n";
        cout << "Distance Traveled Difference: " << abs(dist - other.dist) << " km\n";
        cout << "Carbon Emissions Difference: " << abs(calculateEmissions() - other.calculateEmissions()) << " grams\n";
        cout << "Engine Efficiency Difference: " << abs(eff - other.eff) << " %\n";
    }

    // Destructor
    ~Vehicle() {
        cout << "Destructor: Vehicle '" << vName << "' is being destroyed.\n";
    }
};

int main() {
    int n;
    cout << "Enter the number of vehicles in the showroom: ";
    cin >> n;
    cin.ignore();

    // Dynamically allocate memory for an array of pointers to Vehicle objects
    Vehicle* vehicles[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Vehicle " << i + 1 << ":\n";
        string name;
        double fuel, distance, emiFactor;

        cout << "Enter Vehicle Name: ";
        getline(cin, name);
        cout << "Enter Fuel Consumed (liters): ";
        cin >> fuel;
        cout << "Enter Distance Traveled (km): ";
        cin >> distance;
        cout << "Enter Carbon Emission Factor (grams/liter): ";
        cin >> emiFactor;
        cin.ignore();

        if (fuel == 0 || distance == 0 || emiFactor == 0) {
            cout << "One or more inputs are 0. Default constructor will be used for Vehicle " << i + 1 << ".\n";
            vehicles[i] = new Vehicle(); // Default constructor
        } else {
            vehicles[i] = new Vehicle(name, fuel, distance, emiFactor); // Parameterized constructor
        }
    }

    cout << "\nDetails of all vehicles in the showroom:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nVehicle " << i + 1 << ":\n";
        vehicles[i]->displayDetails();
    }

    // Example comparison between two vehicles
    if (n > 1) {
        cout << "\nComparing the first vehicle with the second vehicle:\n";
        Vehicle* copyVehicle = new Vehicle(*vehicles[0]); // Using the copy constructor
        vehicles[1]->compareWith(*copyVehicle);           // Compare second vehicle with the copied one
        delete copyVehicle;                               // Explicitly call destructor for copyVehicle
    }

    // Freeing allocated memory and calling destructors
    for (int i = 0; i < n; i++) {
        delete vehicles[i]; // Destructor called for each Vehicle object
    }

    cout << "\nAll vehicles have been processed. Exiting the program.\n";
    return 0;
}
