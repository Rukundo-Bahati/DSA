#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
   int a = 1;
   int b = 2;
   int temp = b;
   b = a;
   a = temp;

   double x = 10;
   int y =5;
   double z =(x + 10 )/ (3*y);

   double sales = 95000;
   const double state_value_rate = 0.4;
   const double county_tax_rate = 0.2;

   double state_tax = sales * state_value_rate;
   double county_tax = sales * county_tax_rate;
   double total_tax = state_tax + county_tax;

   cout << a <<endl;
   cout << b <<endl;
   cout << z <<endl;
   cout << "-----------------------------------" <<endl
        << "Total sales : $" << sales <<endl
        << "State tax: $" << state_tax <<endl
        << "County tax: $" << county_tax <<endl
        << "Total Tax: $" << total_tax <<endl;


   double result1 = ceil(1.8);
   cout << result1 <<endl;

   double result2 = pow(2,3);
   cout << result2 <<endl;

  //random numbers
   srand(time(0));
   int number =  rand() % 10;
   cout << number;

}