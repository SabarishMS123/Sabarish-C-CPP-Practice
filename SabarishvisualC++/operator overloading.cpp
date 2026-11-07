#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
  Number(int v) {
        value = v;
    }


    // Member function to overload '~'
    Number operator~() {
        return Number(~value);
    }

    // Friend function to overload '+'
    friend Number operator+(const Number &num1, const Number &num2);

    // Function to display the value
    void display() const {
        cout << value;
    }
};

// Friend function implementation for '+'
Number operator+(const Number &num1, const Number &num2) {
    return Number(num1.value + num2.value);
}

int main() {
	int m,x;
	cout<<"Enter the values to evaluate expression a+(~b):";
	cin>>m>>x;
    Number a(m); // Initialize a with value 10
    Number b(x);  // Initialize b with value 5

    Number result = a + (~b); // Evaluate a + (~b)

    cout << "Result of a + (~b): ";
    result.display(); // Display the result
    cout << endl;

    return 0;
}
