#include <iostream>
#include <string>

using namespace std;

int main() {
    int scores[] = {52, 78, 75, 68, 88, 63, 75, 90, 78};
    int item = 10, k = 3, len = 9;

    for (int j = len - 1; j >= k; j--) {
        scores[j + 1] = scores[j];
    }
    scores[k] = item;

    for (int i = 0; i < len + 1; i++) {
        cout << scores[i] << " ";
    }
    cout << endl;
   
   


    return 0;
}
