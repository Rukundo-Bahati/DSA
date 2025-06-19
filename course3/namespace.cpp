#include <iostream>

using namespace std;

namespace arithmeticOperations{
    float add (float a, float b){
        return a + b;
    }
    float mult (float a, float b){
        return a *b;
    }
}

float val1, val2;

int main(){
   
   cout << "Enter two floats: \n";
   cin >> val1 >> val2;

   cout << "The sum of " << val1 << " and " << val2 << " is " << arithmeticOperations::add(val1,val2) << endl;
   cout << "The product of " << val1 << " and " << val2 << " is " << arithmeticOperations::mult(val1,val2) << endl;    

    return 0;
}