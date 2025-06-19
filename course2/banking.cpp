#include <iostream>
#include <iomanip>

using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
  double balance = 0;
  int choice = 1;

 do{
 cout << "****************************************" <<endl
       << "Enter your choice: "<<endl
       <<"*****************************************" <<endl
       <<"1. Check Balance"<<endl
       <<"2. Deposit money"<<endl
       <<"3. Withdraw money"<<endl
       <<"4. Exit"<<endl;
   cin >> choice;
  
  // checking if the user only enters numbers not letters
    cin.clear();
    while (cin.get() != '\n'){
    continue;
}

   switch (choice)
   {
   case 1: showBalance(balance);
           break;

   case 2: balance +=deposit();
           showBalance(balance);
           break;

    case 3: balance -=withdraw(balance);
            showBalance(balance);
            break;

    case 4: cout << "Thanks for visiting"<<endl;
            break;
   
   default: cout << "Invalid choice"<<endl;
    break;

   }  
 }while(choice != 4);
   

   return 0;
}

void showBalance(double balance){
  cout << "Your Balance is:  $" << setprecision(2) <<fixed <<balance<<endl;
}

double deposit(){

 double amount = 0;
 cout << "Enter amount to deposit: ";
 cin >> amount;
 
 if (amount > 0)
   return amount;
 else {
   cout << "That's not valid amount!"<<endl;  
   return 0;
 }
}

double withdraw(double balance){
    double amount;
    cout << "Enter amount to be withdrawn: ";
    cin >> amount;

    if(amount > balance){
      cout << "Not Enough Balance!"<<endl;
      return 0;
    }
    else if(amount < 0){
        cout << "Invalid amount"<<endl;
        return 0;
    }
    else {
      cout << "You withdrawn " << amount << " Successfully" <<endl;  
      return amount;
    }
}