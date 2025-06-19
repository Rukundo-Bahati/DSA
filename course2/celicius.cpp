#include <iostream>

using namespace std;

int main(){
    double fahrenheitDegree;
    cout << "Fahrenheit Degree: "<<endl;
    cin >> fahrenheitDegree;
    double celcius = (fahrenheitDegree - 32)*5 /9;
    cout << "Celicius: "<< celcius<<endl;
}