#include <iostream>
#include <string>
#include <limits>

using namespace std;


// Function to display fitness metrics with default arguments and categorization
void dspMtrc(const string& usr, int stp = 0, double cal = 0.0, int hr = 0) {
    cout << "Fitness Metrics for " << usr << ":" << endl;
    
    string stpCtgry = (stp >= 10000) ? "Good" : "Bad";
    cout << "Steps: " << stp << " (" << stpCtgry << ")" << endl;

    string calCtgry = (cal >= 500) ? "Good" : "Bad";
    cout << "Calories Burned: " << cal << " kcal (" << calCtgry << ")" << endl;

    string hrCtgry = (hr >= 60 && hr <= 100) ? "Good" : "Bad";
    cout << "Heart Rate: " << hr << " bpm (" << hrCtgry << ")" << endl;
}

int main() {
    string usr;
    int stp ;
    double cal ;
    int hr;

    cout << "Enter your user name: ";
    getline(cin, usr);

    cout << "Enter number of steps (default: 0): ";
    if (!(cin >> stp)) {
        stp = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter calories burned (default: 0.0): ";
    if (!(cin >> cal)) {
        cal = 0.0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter heart rate (default: 0): ";
    if (!(cin >> hr)) {
        hr = 0;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nTracking fitness metrics for " << usr << "...\n" << endl;
    dspMtrc(usr, stp, cal, hr);

    return 0;
}
