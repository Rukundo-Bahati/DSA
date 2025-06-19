#include <iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
int a,b,hypothenuse,counter=0;
for(a=2;a<100;a++)
{
for (b=3; b<a;b++)
{
hypothenuse=sqrt(pow(a,2)+pow(b,2));
if(hypothenuse==sqrt(pow(a,2)+pow(b,2))){
cout<<"("<<a<<","<<b<<")"<<endl;
counter++;
}
}
}
cout<<"Counted:"<<counter<<endl;
return 0;
}