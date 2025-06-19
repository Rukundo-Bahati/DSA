#include <iostream>

using namespace std;

int main(){
    int number;
    int guess;
    int tries;

    srand(time(0));
    number = (rand() % 100 + 1);
     
    cout << "**********NUMBER GEUSSING GAME*********************"<<endl;

    do{
     cout << "Enter a guess(1-100): ";
     cin >> guess;
     tries++;

     if(guess > number) {
      cout <<"Too high"<<endl;
     } 
     else if(guess < number) {
        cout << "Too low!"<<endl;
     } else {
        cout << "CORRECT."<<endl
             << "Number of tries: "<<tries<<endl;
     }
    }while (guess !=number);

       cout << "***********************************************";

    return 0;
}