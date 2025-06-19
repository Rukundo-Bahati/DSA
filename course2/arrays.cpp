#include <iostream>

using namespace std;

void differenceOfEvenAndOdd();
int addNumbers(int num1,int num2);
int addNumbers(int num1,int num2,int num3);

int main(){
	addNumbers(4,7);
	addNumbers(3,5,7);
	differenceOfEvenAndOdd();
	
	return 0;
}

int addNumbers(int num1, int num2){
	cout << num1 + num2<<endl;
}

int addNumbers(int num1,int num2,int num3){
	cout << num1+ num2 + num3;
}

void differenceOfEvenAndOdd(){
	
	int numbers[] = {5,7,12,14,15,9,8,2,3,10};
	int size = sizeof(numbers)/ sizeof(int);
	int oddNumbers[20];
	int evenNumbers[20];
	
	int evenCount = 0; 
    int oddCount = 0;
	
      for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            evenNumbers[evenCount] = numbers[i];
            evenCount++;
        } else {
            oddNumbers[oddCount]  = numbers[i];
            oddCount++;
        }
    }
    
    int sumOfEven = 0;
    int sumOfOdd = 0;
    
    for(int i=0;i<sizeof(evenNumbers)/sizeof(int);i++){
    	sumOfEven += evenNumbers[i];
	}
	 for(int i=0;i<sizeof(oddNumbers)/sizeof(int);i++){
    	sumOfOdd += oddNumbers[i];
	}
	

		//finding the difference
		 int result = sumOfEven -sumOfOdd;
		 cout << result << endl;
}