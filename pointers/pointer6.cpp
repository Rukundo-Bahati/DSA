 #include<iostream>
using namespace std;

int main(){
    
  int a = 7;
  int b = 17;
  int *c = &b;
  *c = 7;
  cout<<"a="<<a<<" and b= "<<b<<endl;
  c = &a;
  *c = 17;
   cout<<"Then a="<<a<<" and b="<<b<<endl;
   cout<<*c<<endl;

    return 0;
}
