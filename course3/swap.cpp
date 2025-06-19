#include <iostream>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

int main(){

    //swapping numbers
    int a=5;
    int b=4;
    cout << "Before swapping: "<<endl
         <<"a= "<< a << ", b= "<< b << endl;

   int temp = b;
   b=a;
   a= temp;

    cout << "After swapping: " <<endl
        <<"a= "<< a << ", b= "<< b << endl;

    cout <<ceil(8.2)<<endl;
    cout <<fmod(2.7,1.2)<<endl;
    cout <<isdigit('5')<<endl;

    char str1[] = "x";  // Use a character array with enough space
    char str2[] = "y";  
    cout<<strcat(str1, str2)<<endl; 
    cout<<ceil(-9.8)<<endl;

   return 0;     
          
}