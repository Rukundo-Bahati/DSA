#include <iostream>

using namespace std;

int findSecondSmallest(int array[], int size){
    int smallest = __INT_MAX__;
    int secondSmallest = __INT_MAX__;

    for(int i=0; i<size; i++){
        if(array[i] < smallest ){
            secondSmallest = smallest;
            smallest = array[i];
        } else if(array[i] < secondSmallest && array[i] != smallest)
            secondSmallest = array[i];    
    }

    if (secondSmallest == __INT_MAX__) {
        cout << "No distinct second smallest element found." << endl;
        return -1;
    }

    return secondSmallest;

}

int main(){

    int arraySize;
    cout << "Enter the size of array: ";
    cin >> arraySize;
    int numbers[arraySize];

    cout << "\n Enter the elements of array: \n";
    for(int i=0; i<arraySize; i++){
    cout << "Array [" << i << "]: ";
    cin >> numbers[i];
    }

    int result = findSecondSmallest(numbers, sizeof(numbers)/sizeof(numbers[0]));
    if(result != -1){
        cout << "The second smallest element in array is : " << result << endl;
    }


    return 0;
}