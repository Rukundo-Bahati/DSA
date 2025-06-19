#include <iostream>
using namespace std;

int countDigit(int number, int digit) {
    // Handle the case where the number is 0 and digit is 0 separately
    if (number == 0 && digit == 0) {
        return 1;
    }

    int count = 0;
    number = abs(number); // Ensure positive number

    while (number > 0) {
        int currentDigit = number % 10; // Extract the last digit
        if (currentDigit == digit) {
            count++;
        }
        number /= 10; // Remove the last digit
    }

    return count;
}

// Test cases
int main() {
    cout << countDigit(32121, 1) << endl;  // Output: 2
    cout << countDigit(33331, 3) << endl;  // Output: 4
    cout << countDigit(33331, 6) << endl;  // Output: 0
    cout << countDigit(3, 3) << endl;      // Output: 1
    cout << countDigit(0, 0) << endl;      // Output: 1 (edge case)
    return 0;
}