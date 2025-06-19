#include <iostream>
using namespace std;

int findMostFrequent(int arr[], int size) {
    int maxCount = 0;
    int mostFrequent = arr[0];
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }
    return mostFrequent;
}

int main() {
    int nbrOfElements;
    cout << "Enter number of elements: ";
    cin >> nbrOfElements;

    if (nbrOfElements <= 0) {
        cout << "Invalid number of elements. Exiting program." << endl;
        return 1;
    }

    int* arrayNum = new int[nbrOfElements]; // Dynamically allocate memory
    cout << "\nEnter " << nbrOfElements << " elements of the array:\n";
    for (int i = 0; i < nbrOfElements; i++) {
        cout << "Array_num[" << i << "]: ";
        cin >> arrayNum[i];
    }

    cout << "\nOriginal array: ";
    for (int i = 0; i < nbrOfElements; i++) {
        cout << arrayNum[i] << " ";
    }
    cout << endl;

    int mostFrequent = findMostFrequent(arrayNum, nbrOfElements);
    cout << "Most occurred number is: " << mostFrequent << endl;

    delete[] arrayNum; // Free dynamically allocated memory
    return 0;
}
