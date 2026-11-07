#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string vName;
    double fuel;
    double dist;
    double emiFactor;
    double eff;

public:
    Vehicle() {
        vName = "Unknown Vehicle";
        fuel = 0;
        dist = 0;
        emiFactor = 2.31;
        eff = 0;
        cout << "Default Constructor: Vehicle initialized with default values.\n";
    }

    Vehicle(const string& name, double f, double d, double eFactor) {
        vName = name;
        fuel = f;
        dist = d;
        emiFactor = eFactor;
        eff = calculateEfficiency();
        cout << "Parameterized Constructor: Vehicle '" << vName << "' initialized.\n";
    }

    double calculateMileage() const {
        return (fuel == 0) ? 0 : dist / fuel;
    }

    double calculateEmissions() const {
        return fuel * emiFactor * 1000;
    }

    double calculateEfficiency() const {
        return (dist == 0 || fuel == 0) ? 0 : (calculateMileage() / 20.0) * 100;
    }

    void displayDetails() const {
        cout << "Vehicle Name: " << vName << endl;
        cout << "Fuel Consumed: " << fuel << " liters\n";
        cout << "Distance Traveled: " << dist << " km\n";
        cout << "Mileage: " << calculateMileage() << " km/l\n";
        cout << "Carbon Emissions: " << calculateEmissions() << " grams\n";
        cout << "Engine Efficiency: " << eff << " %\n";
    }

    ~Vehicle() {
        cout << "Destructor: Vehicle '" << vName << "' is being destroyed.\n";
    }
};

int main() {
    int n;
    cout << "Enter the number of vehicles in the showroom: ";
    cin >> n;
    cin.ignore();

    Vehicle vehicles[n];

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
            vehicles[i] = Vehicle();
        } else {
            vehicles[i] = Vehicle(name, fuel, distance, emiFactor);
        }
    }

    cout << "\nDetails of all vehicles in the showroom:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nVehicle " << i + 1 << ":\n";
        vehicles[i].displayDetails();
    }

    cout << "\nAll vehicles have been processed. Exiting the program.\n";
    return 0;
}
