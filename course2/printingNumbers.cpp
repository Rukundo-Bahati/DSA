#include <iostream>

using namespace std;


void print(int x){

    if(x== 0){
        return;
    }

    print(x-1);
    cout << x <<endl;
}
int main(){
    print(10);

    return  0; 
}