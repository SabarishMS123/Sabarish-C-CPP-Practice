#include <iostream>
#include <string>
inline float kelvinToCelsius(float kelvin) {
    return kelvin - 273.15f;
}
void displayFeverStatus(float celsius) {
    std::string status;
    if (celsius < 36.1f) {
        status = "Below normal temperature";
    } else if (celsius >= 36.1f && celsius <= 37.2f) {
        status = "Normal temperature";
    } else if (celsius > 37.2f && celsius <= 38.0f) {
        status = "Mild fever";
    } else if (celsius > 38.0f && celsius <= 39.0f) {
        status = "Moderate fever";
    } else {
        status = "High fever";
    }
    std::cout << "Fever Monitor: " << status << std::endl;
}

int main() {
    using namespace std;
    float kelvin;
    cout << "Enter temperature in Kelvin: ";
    cin >> kelvin;
    float celsius = kelvinToCelsius(kelvin);
    cout << "Temperature in Celsius: " << celsius << "°C" << endl;
    displayFeverStatus(celsius);
    return 0;
}
