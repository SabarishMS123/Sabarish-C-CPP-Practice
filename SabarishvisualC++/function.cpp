#include <iostream>
#include <string>

using namespace std;


struct Plastic {
    string type;
    double toxicityLevel; 
    double durability;    
    double temperatureResistance; 
};


double calculateSafetyRating(const Plastic& plastic, double safetyFactor = 0.0) {
    double rating = 100.0;

   
    rating -= plastic.toxicityLevel * 10;

   
    rating += plastic.durability * 5;
    rating += plastic.temperatureResistance * 0.5;

    
    rating += safetyFactor;

    return rating;
}


void displayPlasticInfo(const Plastic& plastic, double safetyRating) {
    cout << "Plastic Type: " << plastic.type << endl;
    cout << "Toxicity Level: " << plastic.toxicityLevel << endl;
    cout << "Durability: " << plastic.durability << endl;
    cout << "Temperature Resistance: " << plastic.temperatureResistance << endl;
    cout << "Safety Rating: " << safetyRating << endl;
    cout << "--------------------------" << endl;
}


void inputPlasticData(Plastic& plastic) {
    cout << "Enter Plastic Type: ";
    cin >> plastic.type;
    cout << "Enter Toxicity Level (0.0 to 10.0): ";
    cin >> plastic.toxicityLevel;
    cout << "Enter Durability (1 to 10): ";
    cin >> plastic.durability;
    cout << "Enter Temperature Resistance (degrees Celsius): ";
    cin >> plastic.temperatureResistance;
}

int main() {
    Plastic plastic;

    
    inputPlasticData(plastic);

    
    double safetyRating = calculateSafetyRating(plastic);

    
    displayPlasticInfo(plastic, safetyRating);

    return 0;
}
