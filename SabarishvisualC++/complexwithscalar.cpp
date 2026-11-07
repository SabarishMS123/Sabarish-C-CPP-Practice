#include<iostream>
using namespace std;

class Complex{
private: // Good practice to explicitly state private
    int re, ima;
public:
    // Corrected constructor
    Complex(int re_val = 0, int im_val = 0) : re(re_val), ima(im_val) {}

    // Friend declarations (return type is Complex, not Complex*)
    friend Complex operator *(int S, Complex &other);
    friend Complex operator *(Complex &other, int S);
    friend Complex operator *(Complex &o1 , Complex &o2); // Declaration for Complex * Complex, though not used in main

    // Public setter for initialization
    void setComplex(int r, int i) {
        re = r;
        ima = i;
    }

    void display() {
        cout << "\nResult:" << re << "+i" << ima;
    }
};

// Friend function definitions (outside the class, no 'friend' keyword here)
Complex operator *(int S, Complex &other) {
    // Create a new Complex object and return it
    return Complex(S * other.re, S * other.ima);
}

Complex operator *(Complex &other, int S) {
    // Create a new Complex object and return it
    return Complex(other.re * S, other.ima * S);
}

// Definition for Complex * Complex (if needed, otherwise remove the declaration)
Complex operator *(Complex &o1 , Complex &o2) {
    // Example: (a+ib)*(c+id) = (ac-bd) + i(ad+bc)
    return Complex((o1.re * o2.re) - (o1.ima * o2.ima), (o1.re * o2.ima) + (o1.ima * o2.re));
}


int main() {
    Complex c1, c2, c3; // c2 is not used
    int l;

    cout << "Enter the real and imaginary part of the Complex number1:";
    int temp_re, temp_im;
    cin >> temp_re >> temp_im;
    c1.setComplex(temp_re, temp_im); // Use setter to initialize

    cout << "Enter the lambda value to multiply:";
    cin >> l;

    // Assignment, not redeclaration
    c3 = l * c1;
    c3.display();

    return 0; // Standard practice for main
}