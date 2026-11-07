#include <stdio.h>

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) { // Declare i outside the loop
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Counting sort function for a specific digit (exp)
void countingSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Count array to store digit frequency
    int i;

    // Count occurrences of each digit in the specific place value (exp)
    for (i = 0; i < n; i++) { // Declare i outside the loop
        count[(arr[i] / exp) % 10]++;
    }

    // Update count array with cumulative frequency
    for (i = 1; i < 10; i++) { // Declare i outside the loop
        count[i] += count[i - 1];
    }

    // Build the output array using the count array
    for (i = n - 1; i >= 0; i--) { // Declare i outside the loop
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array back into the original array
    for (i = 0; i < n; i++) { // Declare i outside the loop
        arr[i] = output[i];
    }
}

// Radix Sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n); // Find the maximum number in the array
    int exp;

    // Perform counting sort for each digit
    for (exp = 1; max / exp > 0; exp *= 10) { // Declare exp outside the loop
        countingSort(arr, n, exp);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i; // Declare i outside the loop
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

