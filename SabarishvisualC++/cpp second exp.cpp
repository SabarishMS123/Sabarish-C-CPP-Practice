#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Structure to store ingredient details
struct Ingredient {
    string name;
    int quantity; // In grams
};

// Structure to store recipe details
struct Recipe {
    string name;
    vector<Ingredient> ingredients;
    string dietaryPreference;
    int cookingTime; // In minutes
};

// Structure to store fitness activity details
struct Activity {
    string name;
    int duration; // In minutes
    double caloriesBurned;
};

// Function to add ingredient to pantry (call by value)
void addIngredient(vector<Ingredient> &pantry, Ingredient ingredient) {
    pantry.push_back(ingredient);
}

// Function to check ingredient availability (call by address)
bool checkIngredientAvailability(const vector<Ingredient> &pantry, const Ingredient *ingredient) {
    for (size_t i = 0; i < pantry.size(); ++i) {
        if (pantry[i].name == ingredient->name && pantry[i].quantity >= ingredient->quantity) {
            return true;
        }
    }
    return false;
}

// Function to suggest a recipe with default arguments for dietary restrictions
void suggestRecipe(const vector<Recipe> &recipes, const string &dietaryPreference = "None") {
    cout << "Suggested Recipes:" << endl;
    for (size_t i = 0; i < recipes.size(); ++i) {
        if (dietaryPreference == "None" || recipes[i].dietaryPreference == dietaryPreference) {
            cout << "- " << recipes[i].name << endl;
        }
    }
}

// Function to record workout session (call by value)
void recordWorkout(vector<Activity> &activities, Activity activity) {
    activities.push_back(activity);
}

// Function to update user fitness goals (call by reference)
void updateFitnessGoals(int &goalDuration, double &goalCalories) {
    cout << "Enter new goal duration (minutes): ";
    cin >> goalDuration;
    cout << "Enter new goal calories to burn: ";
    cin >> goalCalories;
}

// Function to display fitness activities
void displayActivities(const vector<Activity> &activities) {
    for (size_t i = 0; i < activities.size(); ++i) {
        cout << "Activity: " << activities[i].name 
             << ", Duration: " << activities[i].duration 
             << " minutes, Calories Burned: " << activities[i].caloriesBurned << " kcal" << endl;
    }
}

// Main function
int main() {
    vector<Ingredient> pantry;
    vector<Recipe> recipes;
    vector<Activity> activities;

    Recipe r1;
    r1.name = "Salad";
    r1.ingredients.push_back({"Lettuce", 100});
    r1.ingredients.push_back({"Tomato", 50});
    r1.dietaryPreference = "Vegetarian";
    r1.cookingTime = 10;
    recipes.push_back(r1);

    Recipe r2;
    r2.name = "Chicken Stir Fry";
    r2.ingredients.push_back({"Chicken", 200});
    r2.ingredients.push_back({"Broccoli", 100});
    r2.dietaryPreference = "Non-Vegetarian";
    r2.cookingTime = 20;
    recipes.push_back(r2);

    int choice;
    bool exit = false;

    while (!exit) {
        cout << "\nHealth and Wellness Application Menu:\n";
        cout << "1. Add Ingredient to Pantry\n";
        cout << "2. Suggest Recipes\n";
        cout << "3. Record Workout\n";
        cout << "4. Update Fitness Goals\n";
        cout << "5. Display Activities\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int quantity;
                cout << "Enter ingredient name: ";
                cin >> name;
                cout << "Enter quantity (grams): ";
                cin >> quantity;
                addIngredient(pantry, Ingredient{name, quantity});
                break;
            }
            case 2: {
                string dietaryPreference;
                cout << "Enter dietary preference (None, Vegetarian, Non-Vegetarian): ";
                cin >> dietaryPreference;
                suggestRecipe(recipes, dietaryPreference);
                break;
            }
            case 3: {
                string name;
                int duration;
                double caloriesBurned;
                cout << "Enter activity name: ";
                cin >> name;
                cout << "Enter duration (minutes): ";
                cin >> duration;
                cout << "Enter calories burned: ";
                cin >> caloriesBurned;
                recordWorkout(activities, Activity{name, duration, caloriesBurned});
                break;
            }
            case 4: {
                int goalDuration;
                double goalCalories;
                updateFitnessGoals(goalDuration, goalCalories);
                break;
            }
            case 5: {
                displayActivities(activities);
                break;
            }
            case 6: {
                exit = true;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }

    return 0;
}

