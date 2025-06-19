#include <iostream>
using namespace std;

// Template function for adding two parameters
template<typename T,typename K>
T addition(T a, K b) {
    return a + b;
}


int main() {
    // Calling the two-parameter addition function
    int sumOfInt1 = addition<int>(12, 14);
    int sumOfDouble = addition<double>(13.545,25.757);
    cout << sumOfInt1 << endl;
    cout << sumOfDouble<<endl;


    return 0;
}
