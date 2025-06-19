#include<iostream>
using namespace std;

int main ()
{
float PI = 3.14;
float *PIptr;
float r=5, A;
float x;
PIptr=&PI; //PIptr contains the address of PI
x=*PIptr; // value stored in PI(3.14)is assigned to x.
A=r*r*x;
cout<<"The area of circle is"<<A<<endl;
return 0;
}
