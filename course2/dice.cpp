#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));
    int face1 = rand() % 6;
    int face2 = rand() % 6;
    cout << "(" <<face1  << "," << face2 << ")" <<endl;
}