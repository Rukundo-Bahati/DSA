#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// CREATING ALIASES
// typedef std::string text_t;
using text_t = std::string;
using number_t = int;

int main(){
  text_t firstName = "Baba";
  number_t six = 6;
  cout << firstName <<std::endl;
  cout << six<< endl;

 //ternary operator
  int marks {80};
  marks >=60 ? cout<< "You pass"<<endl : cout  <<"You fail"<<endl;
  int number {888};
  number % 2 == 1 ? cout << "ODD"<<endl : cout << "Even"<<endl;

 //nested loops
  int rows;
  int columns;
  char symbol;
  cout << "How many rows?: ";
  cin >>rows;
  cout << "How many columns?: ";
  cin >> columns;
  cout << "Enter the symbol to use: ";
  cin >> symbol;

  for(int i = 1; i<=rows; i++){
    for(int j = 1; j<=columns; j++){
        cout << symbol;
    }
    cout << '\n';
  }


 //removing whitespaces
  short age;
  string name;
  cout << "What's your age? : " <<endl;
  cin >> age;
  cout << "What's your full name: ? " <<endl;
  getline(cin >> ws,name);   //use whiteSpace (ws) to remove the new line buffer
  cout << "Your age: " << age <<endl 
       << "Your full name: " << name <<endl;

  //math functions exercise1
   cout << "------------------------------------------------------------------------------"<<endl;
   double side1;
   double side2;

   cout << "Enter side1 and side2 of a triangle: "<<endl;
   cin >> side1 >> side2;

   double hypothenuse = sqrt(pow(side1,2) + pow(side2,2)); 
   cout << "Hypothenuse is: " << hypothenuse <<endl;

 return 0;
}