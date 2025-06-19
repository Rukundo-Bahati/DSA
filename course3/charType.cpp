#include <iostream>
#include <string>

using namespace std;

int main(){

    char character;

    cout << "Enter any character: ";
    cin >> character; 

    //alphabet checking   
    if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')){
    cout << character << " Is an alphabet."<<endl;
    } else if(character >= '0' && character <= '9'){
   cout << character << " is a digit."<<endl;
    } else {
        cout << character << " is a special character" <<endl;
    }

    return 0;

}