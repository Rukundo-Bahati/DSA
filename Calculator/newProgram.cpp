#include <iostream>

using namespace std;

int main() {
    int count = 0;
 for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
        cout <<"i= " << i << "j= " << j<<endl;
        count++;
    }
 }
 cout << "Number of times is " <<count << endl;
 return 0;
}