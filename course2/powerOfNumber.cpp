#include <iostream>

using namespace std;

int power(int base, int exponent){
 if(exponent == 0){
    return 1;
 } 
 int smallOutput = power(base,exponent-1);
 return base * smallOutput;
}
int main(){
      cout << power(5,3)<<endl;
    return 0;
}