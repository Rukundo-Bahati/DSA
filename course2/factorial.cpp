#include <iostream>

using namespace std;

int fact(int n){
    if(n < 0 ) return -1;
    if(n == 0) return 1;

    int smallAnswer = fact(n-1);
    return n * smallAnswer;
}

int fibonnaci(int number){
    if(number == 0){
        return 1;
    }
    if(number == 1){
        return 0;
    }
    int smallOutput1 = fibonnaci(number - 1);
    int smallOutput2 = fibonnaci(number -2);

    return smallOutput1 + smallOutput2;
}

int sumOfDigits(int x){
    int sum;
    if(x/10 == 0){
        return x;
    }
    int smallAnswer = sumOfDigits(x/10);
    return x % 10 + smallAnswer;
}

int main(){
 int n = 5;
 int n2 = 1335;

 int answer = fact(n);
 int resultOfDigits = sumOfDigits(n2);

 cout << "Factorial of " << n << " is " << answer << endl;
 cout << "Sum Of Digits of "<< n2 << " is " << resultOfDigits<<endl;
 cout << "Fibonaci at position is "<<fibonnaci(10)<<endl;

 return 0;
}