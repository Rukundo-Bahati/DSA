#include<iostream>
using namespace std;

int main(){

  int a = 50;
  int *ptr = &a;
  cout<<(*ptr)++<<endl;
  cout<<a<<endl;
  int *q=ptr;
  (*q)++;
  cout<<(*ptr)++<<endl;
  cout<<*q<<endl;
  cout<<a<<endl;

   return 0;
}
