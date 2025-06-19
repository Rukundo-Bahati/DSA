#include <iostream>
#include <cmath>

using namespace std;

int power(int a, int b);

int main(){
 int num = power(3,3);
 cout << "Squared number is: "<< num<<'\n';

 double numerator = 5.75;
 double denominator = 4.2;

 double result = fmod(numerator,denominator);
 cout << result<<endl;

 cout << log10(5)<<endl;
 cout << sin(30)<<endl;
 cout << fmax(-3,-6)<<endl;

 return 0;
}


int power(int a,int b){
    int pow = 1;
    for(int i=1;i<=b; i++){
     pow  *= a;
    }
    return pow;
} 
