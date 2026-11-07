
//<----------------------Method 1----------------------------->
/*
#include <iostream>
using namespace std;

int main() {
    int temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;

    if (temperature > 30) {
        cout << "It's hot outside!" << endl;
    } else if (temperature > 20) {
        cout << "The weather is pleasant." << endl;
    } else {
        cout << "It's cold outside!" << endl;
    }

    return 0;
}
*/

//<----------------------Method 2----------------------------->
/*
#include <iostream>
using namespace std;

int main() {
    int temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;

    cout << (temperature > 30 ? "It's hot outside!" : (temperature > 20 ? "The weather is pleasant." : "It's cold outside!")) << endl;

    return 0;
}
*/
//<----------------------Method 3----------------------------->
/*
#include <iostream>
using namespace std;

int main() {
    int temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;

    switch (temperature / 10) {
        case 0: case 1: case 2:
            cout << "It's cold outside!" << endl;
            break;
        case 3:
            cout << "The weather is pleasant." << endl;
            break;
        default:
            cout << "It's hot outside!" << endl;
    }

    return 0;
}
*/
//<----------------------Method 4----------------------------->
/*
#include <iostream>
using namespace std;

string getWeatherCondition(int temperature) {
    if (temperature > 30) {
        return "It's hot outside!";
    } else if (temperature > 20) {
        return "The weather is pleasant.";
    } else {
        return "It's cold outside!";
    }
}

int main() {
    int temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;

    cout << getWeatherCondition(temperature) << endl;

    return 0;
}
*/
//<----------------------Method 5----------------------------->
/*
#include <iostream>
using namespace std;

int main() {
    int temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;

    string conditions[] = {"It's cold outside!", "It's cold outside!", "It's cold outside!",
                           "The weather is pleasant.", "It's hot outside!"};
    int index = temperature / 10;
    if (index > 4) index = 4; // Handle temperatures above 40
    cout << conditions[index] << endl;

    return 0;
}
*/
//<----------------------Method 6----------------------------->
#include <iostream>
#include <map>
using namespace std;

int main() {
    int temperature;
    cout << "Enter the temperature: ";
    cin >> temperature;

    map<int, string> conditions = {
        {30, "It's hot outside!"},
        {20, "The weather is pleasant."},
        {INT_MIN, "It's cold outside!"} // Default case for temperatures below 20
    };

    string result = conditions[INT_MIN];
    for (const auto& [key, value] : conditions) {
        if (temperature > key) {
            result = value;
            break;
        }
    }
    cout << result << endl;

    return 0;
}
