#include <iostream>
using namespace std;

bool isKaprekarNumber(int n) {
    if (n == 1) {
        return true;
    }

    int square = n * n;
    int temp = square;
    int count = 0;

    // Counting the number of digits in the square
    while (temp > 0) {
        count++;
        temp /= 10;
    }

    int powerOfTen = 1;
    for (int i = 1; i < count; i++) {
        powerOfTen *= 10; // Calculate power of 10 for splitting
        int left = square / powerOfTen;  // Left part
        int right = square % powerOfTen; // Right part

        // Check if the sum of left and right equals the original number
        if (right != 0 && (left + right == n)) {
            return true;
        }
    }

    return false;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isKaprekarNumber(num)) {
        cout << num << " is a Kaprekar number." << endl;
    } else {
        cout << num << " is not a Kaprekar number." << endl;
    }

    return 0;
}
