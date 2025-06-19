#include <iostream>

using namespace std;

int difference(int arr[],int size);

int main(){
    int numbers[] = {4,6,7,3,6,8,11,2,9,11};
    int size = sizeof(numbers) / sizeof(int);
    int diff = difference(numbers,size);
    cout << diff;

}

int difference(int arr[],int size){ 
    short sumOfEven= 0;
    short sumOfOdd = 0;

    for(int i = 0; i<size; i++){
        if(arr[i] % 2 ==0){
            sumOfEven += arr[i];
        } else{
            sumOfOdd += arr[i];
        }
    }
    return sumOfEven - sumOfOdd; 
}