#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

// User-defined exception for future dates
class FutureDateException : public runtime_error {
public:
    FutureDateException(const string& message) : runtime_error(message) {}
};

// User-defined exception for join date before DOB
class InvalidJoinDateException : public runtime_error {
public:
    InvalidJoinDateException(const string& message) : runtime_error(message) {}
};

// Class to represent a date
class Date {
private:
    int day;
    int month;
    int year;

public:
    // Default constructor
    Date() : day(1), month(1), year(1970) {}

    // Constructor with initialization
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        if (d < 1 || d > 31 || m < 1 || m > 12) {
            throw invalid_argument("Invalid date values.");
        }
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool operator>(const Date& other) const {
        if (year != other.year) return year > other.year;
        if (month != other.month) return month > other.month;
        return day > other.day;
    }

    bool operator<(const Date& other) const {
        return !(*this > other) && !(*this == other);
    }

    bool operator==(const Date& other) const {
        return (day == other.day && month == other.month && year == other.year);
    }
};

Date getCurrentDate() {
    int d, m, y;
    cout << "Enter today's date (dd mm yyyy): ";
    cin >> d >> m >> y;
    return Date(d, m, y);
}

class Sportsperson {
public:
    string name;
    Date dob;
    Date joinDate;

    Sportsperson(string n, Date d, Date j) : name(n), dob(d), joinDate(j) {}

    int calculateAge(const Date& today) const {
        if (dob > today) {
            throw FutureDateException("Date of birth cannot be in the future.");
        }
        int age = today.getYear() - dob.getYear();
        if (today.getMonth() < dob.getMonth() || (today.getMonth() == dob.getMonth() && today.getDay() < dob.getDay())) {
            age--;
        }
        return age;
    }

    int calculateExperience(const Date& today) const {
        if (joinDate > today) {
            throw FutureDateException("Join date cannot be in the future.");
        }
        if (joinDate < dob) {
            throw InvalidJoinDateException("Join date cannot be earlier than date of birth.");
        }
        int experience = today.getYear() - joinDate.getYear();
        if (today.getMonth() < joinDate.getMonth() || (today.getMonth() == joinDate.getMonth() && today.getDay() < joinDate.getDay())) {
            experience--;
        }
        return experience;
    }
};

string generateRank(int index) {
    string rank = "";
    while (index >= 0) {
        rank = static_cast<char>('A' + (index % 26)) + rank;
        index = index / 26 - 1;
    }
    return rank;
}

Date readDate(const string& dateType, const Date& today, const Date& dob) {
    int d, m, y;
    char delimiter;
    while (true) {
        cout << "Enter " << dateType << " (dd/mm/yyyy): ";
        cin >> d >> delimiter >> m >> delimiter >> y;

        try {
            Date inputDate(d, m, y);
            if (dateType == "Date of Birth" && inputDate > today) {
                throw FutureDateException("Date of birth cannot be in the future.");
            }
            if (dateType == "Join Date" && inputDate > today) {
                throw FutureDateException("Join date cannot be in the future.");
            }
            if (dateType == "Join Date" && inputDate < dob) {
                throw InvalidJoinDateException("Join date cannot be earlier than date of birth.");
            }
            return inputDate;
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << " Please re-enter.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
}

int main() {
    Date today = getCurrentDate();
    cout << "Today's Date: " << today.getDay() << "/" << today.getMonth() << "/" << today.getYear() << endl;

    vector<Sportsperson> sportspersons;
    int n;

    cout << "Enter the number of sportspersons: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name;
        cout << "\nEnter details for Sportsperson " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin >> name;
        Date dob = readDate("Date of Birth", today, Date(1, 1, 1900));
        Date joinDate = readDate("Join Date", today, dob);
        sportspersons.emplace_back(name, dob, joinDate);
    }

    cout << "\nSportspersons' Information:\n";
    for (size_t i = 0; i < sportspersons.size(); ++i) {
        try {
            int age = sportspersons[i].calculateAge(today);
            int experience = sportspersons[i].calculateExperience(today);
            string rank = generateRank(i);
            cout << rank << ". " << sportspersons[i].name
                 << " - DOB: " << sportspersons[i].dob.getDay() << "/" << sportspersons[i].dob.getMonth() << "/" << sportspersons[i].dob.getYear()
                 << ", Join Date: " << sportspersons[i].joinDate.getDay() << "/" << sportspersons[i].joinDate.getMonth() << "/" << sportspersons[i].joinDate.getYear()
                 << ", Age: " << age << ", Experience: " << experience << " years" << endl;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    return 0;
}
