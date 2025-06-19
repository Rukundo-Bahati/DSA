#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int count = 0;

  for(int a = 2; a<100; a++){
    for(int b = a + 1; b<100; b++){
      double hypothenuse = sqrt(a* a + b * b);
      if(hypothenuse == static_cast<int>(hypothenuse) && hypothenuse < 100){
        cout << "(" << a << "," << b << ")" << endl;
          count ++;
      }
    }
  }

  cout << "Total Pairs: " << count << endl;

  return 0;
}