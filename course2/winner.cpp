#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    srand(time(0));
    int random = rand() % 5 + 1;
    switch (random)
    {
    case 1:
        cout << "You win a bumper sticker";
        break;
    case 2:
        cout << "You win a t-shirt";
        break;
    case 3:
        cout << "You win a free lunch";
        break;
    case 4:
        cout << "You win a gift card";
        break;
    case 5:
        cout << "You win a concert ticket";
        break;
    
    default:
        break;
    }

    return 0;
}