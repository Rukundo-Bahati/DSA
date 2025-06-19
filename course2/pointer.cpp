#include <iostream>

using namespace std;

int main(){

  int sum1,sum2,i;
  int a[5] = {10,20,30,40,50};
  for(sum1 = *a, i=1; i<5; i++){
    sum1 += *(a+i);
  }
    cout << sum1 << endl;

    int *p;
    p=a;
    for(sum2 = *a, p= a+1; p<a+5; p++){
        sum2 += *p;
    }
    cout << sum2 << endl;

    return 0;
}