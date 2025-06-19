#include <iostream>

using namespace std;

void bubbleSort(int arr[], int size) {
    cout << "\tBubble Sort" << endl;
    for (int i = 0; i < size - 1; i++) {
        int check = 0;
        for (int j = 0; j < size - i - 1; j++) { // Corrected
            cout << "i= " << i << " j= " << j << " i*j= " << i * j << endl;
            if (arr[j] > arr[j + 1]) {
                check = 1;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (check == 0)
            return;
    }
}

void insertionSort(int arr[], int size) {
    cout << "\tInsertion Sort" << endl;
    int key, j;
    for (int i = 1; i < size; i++) { // Fixed redeclaration of i
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int size) {
    cout << "\tSelection Sort" << endl;
    for (int i = 0; i < size - 1; i++) {
        int targetIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[targetIndex]) {
                targetIndex = j;
            }
        }
        swap(arr[i], arr[targetIndex]);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


void quickSort(int arr[], int low, int high) {
    if (low >= high) return; // Base case: array is already sorted
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[++i], arr[j]); // Move smaller elements to the left
        }
    }
    swap(arr[++i], arr[high]); // Place the pivot in its correct position
    quickSort(arr, low, i - 1);  // Sort the left subarray
    quickSort(arr, i + 1, high); // Sort the right subarray
}

int main() {

    int array[] = {5, 9, 8, 1, 3, 2, 4, 6, 7, 10};
    int size = sizeof(array) / sizeof(int);

    // bubbleSort(array, size);
    // insertionSort(array, size);
    // selectionSort(array, size);
    // mergeSort(array, 0, size - 1);
    quickSort(array, 0, size - 1);

    cout << "\nSorted Array: ";
    for (int k = 0; k < size; k++) {
        cout << array[k] << "\t";
    }
    cout << endl;

    return 0;
}