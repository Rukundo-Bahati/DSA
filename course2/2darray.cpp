#include <iostream>

using namespace std;

void display(int arr[2][], int r,int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout << arr[i][j]<<endl;
        }
    }
}

int main() {
    int array[3][4] = {
       {10, 11, 12, 13},
       {14, 15, 16, 17},
       {18, 19, 20, 20}
    };

    int array2[][4] = {10,11,12,13,14,15,16,17,18,19,20,21};
    int i, j;
        
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            // cout << array[i][j] << " ";
        }
        // cout << endl;
    }
    // cout << array2[2][1];

  //a
  int a[][2] = {
    {12,14},
    {14,15}
  };
  display(a,2,2);


    return 0;
}
