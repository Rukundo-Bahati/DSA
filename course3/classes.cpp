#include <iostream>

using namespace std;

class Person{

    private:
    string first;
    string last;

    public:
    void setFirstName(string first){
        this->first = first;
    }
    void getName(){
        // return first + " " + last;
    }
    void setLastName(string last){
        this->last = last;
    }

    void printFullName(){cout << "First name: " << first << ", Second name: " << last<<endl;}
};


class Employee : public Person {

} ;

int main() {  

  Person person;
  person.setFirstName("Baba");
  person.setLastName("Lao");
  person.printFullName();

  Employee e;
  e.setFirstName("Emmy");
  e.printFullName();

  Person *person2 = new Person();
  person2->setFirstName("Pro");
  person2->printFullName();
  
 
    return 0;
}