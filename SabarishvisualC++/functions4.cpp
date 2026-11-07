#include <iostream>
#include <string>

using namespace std;


void showConclusion(int grade);
void showConclusion(string gradeName);

int main() {
    int grade;

    cout << "Enter the grade of plastic (1 to 7): ";
    cin >> grade;
    showConclusion(grade);
    switch (grade) {
        case 1:
            showConclusion("Polyethylene Terephthalate (PETE)");
            break;
        case 2:
            showConclusion("High-Density Polyethylene (HDPE)");
            break;
        case 3:
            showConclusion("Polyvinyl Chloride (PVC)");
            break;
        case 4:
            showConclusion("Low-Density Polyethylene (LDPE)");
            break;
        case 5:
            showConclusion("Polypropylene (PP)");
            break;
        case 6:
            showConclusion("Polystyrene (PS)");
            break;
        case 7:
            showConclusion("Other (includes polycarbonate and polylactic acid)");
            break;
        default:
            cout << "Invalid grade! Please enter a number between 1 and 7." << endl;
            break;
    }

    return 0;
}

// Function definition for integer grade input
void showConclusion(int grade) {
    cout << "You entered grade: " << grade << endl;
    // Additional conclusions based on the grade can be added here
}

// Function definition for string grade name input
void showConclusion(string gradeName) {
    cout << "Plastic type: " << gradeName << endl;
    if (gradeName == "Polyethylene Terephthalate (PETE)") {
        cout << "Conclusion: Widely recycled, often used for beverage bottles." << endl;
    } else if (gradeName == "High-Density Polyethylene (HDPE)") {
        cout << "Conclusion: Widely recycled, often used for milk jugs and detergent bottles." << endl;
    } else if (gradeName == "Polyvinyl Chloride (PVC)") {
        cout << "Conclusion: Not widely recycled, used for plumbing pipes and shower curtains." << endl;
    } else if (gradeName == "Low-Density Polyethylene (LDPE)") {
        cout << "Conclusion: Sometimes recycled, used for plastic bags and food wraps." << endl;
    } else if (gradeName == "Polypropylene (PP)") {
        cout << "Conclusion: Sometimes recycled, used for yogurt containers and straws." << endl;
    } else if (gradeName == "Polystyrene (PS)") {
        cout << "Conclusion: Not widely recycled, used for disposable coffee cups and plastic food boxes." << endl;
    } else if (gradeName == "Other (includes polycarbonate and polylactic acid)") {
        cout << "Conclusion: Rarely recycled, includes various other types of plastics." << endl;
    } else {
        cout << "Conclusion: Unknown plastic type." << endl;
    }
}
