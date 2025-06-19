#include <iostream>

using namespace std;
void happyBirthDay(string name);
double square(double length);

int main(){
  string name = "Baba";
  happyBirthDay(name);


 double areaOfSquare = square(4);
 cout << areaOfSquare << endl;

  return 0;
}

void happyBirthDay(string name){
    cout << "Happy birthday to you! " << name<<"\n";
    cout << "Happy birthday to you!\n";
    cout << "Happy birthday to you!\n";
}

double square(double length){
    return length * length;
}