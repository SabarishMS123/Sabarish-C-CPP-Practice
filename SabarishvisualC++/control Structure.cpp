#include <iostream>
using namespace std;

void displayMenu() {
    cout << "Smart Fitness Tracker Menu:\n";
    cout << "1. Track Steps\n";
    cout << "2. Monitor Heart Rate\n";
    cout << "3. Log Calories\n";
    cout << "4. Check Daily Goals\n";
    cout << "5. Display Weekly Activity Summary\n";
    cout << "6. Exit\n";
}

void checkDailyGoals(int steps, int calories) {
    int stepsGoal, caloriesGoal;
    cout << "\nEnter the Steps Goal and Calories Goal: ";
    cin >> stepsGoal >> caloriesGoal;

    string stepsStatus = (steps >= stepsGoal) ? "Steps goal reached!" : "Steps goal not reached.";
    string caloriesStatus = (calories <= caloriesGoal) ? "Calories goal maintained!" : "Calories goal exceeded.";
    
    cout << stepsStatus << "\n" << caloriesStatus << "\n";
}

void displayWeeklySummary(int stepsPerDay[], int heartRatePerDay[], int caloriesPerDay[], int size) {
    cout << "Weekly Activity Summary:\n";
    for (int i = 0; i < size; i++) {
        cout << "Day " << (i + 1) << ": " 
             << stepsPerDay[i] << " steps, "
             << heartRatePerDay[i] << " bpm, "
             << caloriesPerDay[i] << " calories\n";
    }
}

int main() {
    int stepsPerDay[7] = {0}; // Array to store steps for each day
    int heartRatePerDay[7] = {0}; // Array to store heart rate for each day
    int caloriesPerDay[7] = {0}; // Array to store calories for each day
    int choice;
    int dayIndex = 0; // To track which day we are on

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (dayIndex < 7) {
                    cout << "Enter steps taken for day " << (dayIndex + 1) << ": ";
                    cin >> stepsPerDay[dayIndex];
                    cout << "Steps recorded: " << stepsPerDay[dayIndex] << "\n";
                } else {
                    cout << "Weekly tracking complete. Please display the summary.\n";
                }
                break;
            case 2:
                if (dayIndex < 7) {
                    cout << "Enter heart rate for day " << (dayIndex + 1) << ": ";
                    cin >> heartRatePerDay[dayIndex];
                    if (heartRatePerDay[dayIndex] > 100) {
                        cout << "Warning: High heart rate!\n";
                    } else {
                        cout << "Heart rate is normal.\n";
                    }
                } else {
                    cout << "Weekly tracking complete. Please display the summary.\n";
                }
                break;
            case 3:
                if (dayIndex < 7) {
                    cout << "Enter calories consumed for day " << (dayIndex + 1) << ": ";
                    cin >> caloriesPerDay[dayIndex];
                    cout << "Calories recorded: " << caloriesPerDay[dayIndex] << "\n";
                } else {
                    cout << "Weekly tracking complete. Please display the summary.\n";
                }
                break;
            case 4:
                if (dayIndex > 0) {
                    checkDailyGoals(stepsPerDay[dayIndex - 1], caloriesPerDay[dayIndex - 1]);
                } else {
                    cout << "No data available to check goals.\n";
                }
                break;
            case 5:
                displayWeeklySummary(stepsPerDay, heartRatePerDay, caloriesPerDay, 7);
                dayIndex = 7; // Mark the week as complete
                break;
            case 6:
                cout << "Exiting Smart Fitness Tracker.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        // Increment the day index after tracking steps, heart rate, and calories
        if (choice >= 1 && choice <= 3 && dayIndex < 7) {
            dayIndex++;
        }

    } while (choice != 6);

    cout << "Goodbye!\n";
    return 0;
}
