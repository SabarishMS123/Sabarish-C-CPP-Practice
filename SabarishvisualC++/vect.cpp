#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Initialize a vector of integers
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use a lambda function to filter out even numbers
    std::cout << "Odd numbers are: ";
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        if (num % 2 != 0) {
            std::cout << num << " ";
        }
    });

    return 0;
}
