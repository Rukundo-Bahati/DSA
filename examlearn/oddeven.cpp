#include <iostream>

int oddMinusEven(int arr[], int size) {
    int sumOdd = 0;
    int sumEven = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 != 0) {  // Odd number
            sumOdd += arr[i];
        } else {                // Even number
            sumEven += arr[i];
        }
    }

    return sumOdd - sumEven;  // X - Y
}

// Example usage:
int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);  // Calculate array size

    std::cout << "Difference (X - Y): " << oddMinusEven(numbers, size) << std::endl;
    return 0;
}