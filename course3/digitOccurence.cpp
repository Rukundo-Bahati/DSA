#include<bits/stdc++.h>
using namespace std;

int countDigit(int number, int digit){
/// base
if(number==0){
return 0;
}
/// recursive
int smallAns = countDigit(number/10, digit);
/// calculation
int last_digit = number%10;

if(last_digit==digit){
return 1 + smallAns;
} else{
return smallAns;
 }
}

int main(){
cout<<countDigit(10020,0);
return 0;
}