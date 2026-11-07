#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// ANSI escape codes for text highlighting (for compatible terminals)
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RED_BG    "\033[41m"
#define GREEN_BG  "\033[42m"
#define YELLOW_BG "\033[43m"
#define BLUE_BG   "\033[44m"
#define MAGENTA_BG "\033[45m"
#define CYAN_BG   "\033[46m"
#define WHITE_BG  "\033[47m"

// --- Border Manipulators ---

ostream& single_border(ostream& os) {
  os << "--------------------------------------------------------------------------------" << endl;
  return os;
}

ostream& double_border(ostream& os) {
  os << "================================================================================" << endl;
  return os;
}

ostream& custom_border(ostream& os, char borderChar) {
  os << string(80, borderChar) << endl;
  return os;
}

struct CustomBorderManipulator {
  char borderChar;
  CustomBorderManipulator(char c) : borderChar(c) {}
  friend ostream& operator<<(ostream& os, const CustomBorderManipulator& manip) {
    return custom_border(os, manip.borderChar);
  }
};

CustomBorderManipulator border(char c) {
  return CustomBorderManipulator(c);
}

// --- Text Highlighting Manipulators ---
ostream& bold(ostream& os) { return os << BOLD; }
ostream& red(ostream& os) { return os << RED; }
ostream& green(ostream& os) { return os << GREEN; }
ostream& yellow(ostream& os) { return os << YELLOW; }
ostream& blue(ostream& os) { return os << BLUE; }
ostream& magenta(ostream& os) { return os << MAGENTA; }
ostream& cyan(ostream& os) { return os << CYAN; }
ostream& white(ostream& os) { return os << WHITE; }
ostream& red_bg(ostream& os) { return os << RED_BG; }
ostream& green_bg(ostream& os) { return os << GREEN_BG; }
ostream& yellow_bg(ostream& os) { return os << YELLOW_BG; }
ostream& blue_bg(ostream& os) { return os << BLUE_BG; }
ostream& magenta_bg(ostream& os) { return os << MAGENTA_BG; }
ostream& cyan_bg(ostream& os) { return os << CYAN_BG; }
ostream& white_bg(ostream& os) { return os << WHITE_BG; }
ostream& reset_style(ostream& os) { return os << RESET; }

// --- Phone Number Formatting Manipulator ---
ostream& format_phone(ostream& os, const string& phone, const string& format) {
    string formattedPhone = phone;

    if (format == "US") {
        if (phone.length() == 10) {
            formattedPhone = "(" + phone.substr(0, 3) + ") " + phone.substr(3, 3) + "-" + phone.substr(6, 4);
        }
         else {
            os << RED << "Error: US phone number must be 10 digits.  Displaying raw number." << RESET;
        }
    } else if (format == "IN") {
        if (phone.length() == 10) {
             formattedPhone = phone.substr(0, 4) + "-" + phone.substr(4, 6);
        }
        else{
             os << RED << "Error: Indian phone number must be 10 digits. Displaying raw number." << RESET;
        }
    }
     else {
        os << RED << "Error: Unknown phone number format. Displaying raw number." << RESET;
    }
    os << formattedPhone;
    return os;
}

struct PhoneFormatManipulator {
    string phone;
    string format;
    PhoneFormatManipulator(const string& p, const string& f) : phone(p), format(f) {}
    friend ostream& operator<<(ostream& os, const PhoneFormatManipulator& manip) {
        return format_phone(os, manip.phone, manip.format);
    }
};

PhoneFormatManipulator phone_format(const string& phone, const string& format) {
    return PhoneFormatManipulator(phone, format);
}

// --- NEET Registrant Display Function ---
void display_neet_registrant(ostream& os,
                           const string& name,
                           const string& reg_number,
                           const string& phone_number,
                           const string& email,
                           const string& address,
                           const string& city,
                           const string& state,
                           const string& pincode) {
  os << double_border;
  os << bold << "NEET Registrant Information" << reset_style << endl;
  os << double_border;
  os << left << setw(20) << "Name:" << green << name << reset_style << endl;
  os << left << setw(20) << "Registration Number:" << blue << reg_number << reset_style << endl;
  os << left << setw(20) << "Phone Number:" << phone_format(phone_number, "IN") << reset_style << endl;
  os << left << setw(20) << "Email:" << yellow << email << reset_style << endl;
  os << left << setw(20) << "Address:" << address << reset_style << endl;
  os << left << setw(20) << "City:" << city << reset_style << endl;
  os << left << setw(20) << "State:" << state << reset_style << endl;
  os << left << setw(20) << "Pincode:" << pincode << reset_style << endl;
  os << double_border;
}

int main() {
  // NEET registrant data input
  string name, reg_number, phone_number, email, address, city, state, pincode;

  cout << "Enter NEET Registrant Details:" << endl;
  cout << "Name: ";
  getline(cin >> ws, name);
  cout << "Registration Number: ";
  getline(cin >> ws, reg_number);
  cout << "Phone Number: ";
  getline(cin >> ws, phone_number);
  cout << "Email: ";
  getline(cin >> ws, email);
  cout << "Address: ";
  getline(cin >> ws, address);
  cout << "City: ";
  getline(cin >> ws, city);
  cout << "State: ";
  getline(cin >> ws, state);
  cout << "Pincode: ";
  getline(cin >> ws, pincode);

  // Display the information using the custom manipulators and function
  display_neet_registrant(cout, name, reg_number, phone_number, email, address, city, state, pincode);

  cout << border('*') << endl;
  cout << bold << red_bg << white << "Important Instructions:" << reset_style << endl;
  cout << "1. Please verify all details carefully." << endl;
  cout << "2. Carry your registration number to the exam hall." << endl;
  cout << border('*') << endl;

  return 0;
}

