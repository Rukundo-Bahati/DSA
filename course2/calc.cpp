#include <iostream>
#include <cmath>

using namespace std;

int main(){
    char option;
    double number1;
    double number2;
    double result {};

    cout << "**********CALCULATOR************"<<endl;

    cout << "Choose Option(+,-,*,/): ";
    cin >> option;

    cout << "Enter number 1: ";
    cin >> number1;

    cout << "Enter number 2: ";
    cin >> number2;

    switch (option)
    {
    case '+':
        result = number1 + number2;
        cout << "Result: " << result <<endl;
        break;

    case '-':
        result = number1 - number2;
        cout << "Result: " << result <<endl;
        break;

    case '*':
        result = number1 * number2;
        cout << "Result: " << result <<endl;
        break;

    case '/':
        result = number1 / number2;
        cout << "Result: " << result <<endl;
        break;    
    
    default:
        cout << "Invalid operator"<<endl;
        break;
    }

    return 0;
}