#include <iostream>

using namespace std;
char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player,char computer);


int main(){
  char player;
  char computer;

  player = getUserChoice();
  cout << "Your choice: ";
  showChoice(player);

  computer = getComputerChoice();
  cout << "Computer's choice: ";
  showChoice(computer);

  chooseWinner(player,computer);


    return 0;
}

//functions
char getUserChoice(){
  
 char player;
 cout << "\t\tRock-Paper-Scissors Game" <<endl;

  do{
  cout << "Choose one of the following " <<endl
       << "***************************" <<endl
       << "'r' for rock"<<endl
       << "'p' for paper"<<endl
       << "'s' for scissors"<<endl;
       cin >> player;
  }while(player != 'r' && player != 'p' && player != 's');

   return player;
}

char getComputerChoice(){

   srand(time(0));
   int randomChoice = (rand() % 3+1 );
    
   switch (randomChoice){
   case 1: return 'r';
   case 2: return 'p';
   case 3: return 's';
   }
   return 0;

}

void showChoice(char choice){

switch (choice){

 case 'r': cout << "Rock\n";
           break;
 case 's': cout << "Scissors\n";
           break;
 case 'p': cout << "Paper\n";
           break;          

 default:
    break;
}
}

void chooseWinner(char player,char computer){
 
  switch (player){
  case 'r': if(computer == 'r') {
                cout << "It's a tie\n";
            } else if(computer == 'p'){
                cout << "You loose\n";
            } else {
                cout << "You Win!\n";
            }
            break;

   case 'p': if(computer == 'p') {
                cout << "It's a tie\n";
            } else if(computer == 's'){
                cout << "You loose\n";
            } else {
                cout << "You Win!\n";
            }
            break;

   case 's': if(computer == 's') {
                cout << "It's a tie\n";
            } else if(computer == 'p'){
                cout << "You loose\n";
            } else {
                cout << "You Win!\n";
            }
            break;          
  default:
    break;
  }
}