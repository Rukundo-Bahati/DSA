#include <iostream>

using namespace std;

int main() {
  
   int abc = 5;
   cout << "The value of abc is "<<abc <<endl;
   cout << "The address of abc is " << &abc << endl;

   double def = 5.6;
   cout << "The value of def is " << def <<endl;
   cout << "The address of def " <<&def <<endl;

   int *ptr = &abc;
   double *fed = &def;
   cout << "The value of abc is "<<*ptr <<endl;
   cout << "The address of abc is " <<ptr << endl;
   cout << "The value of def is " <<*fed <<endl;
   cout << "The address of def " <<fed <<endl;

   //change the value
   *ptr = 55;
   *fed = 16.5;
   cout << "The Value of abc is "<<*ptr <<endl;
   cout << "The address of abc is "<<ptr<<endl;
   cout << "The value of def is " << fed<<endl;
   cout << "The value address of def " <<fed<<endl;

    return 0;
}