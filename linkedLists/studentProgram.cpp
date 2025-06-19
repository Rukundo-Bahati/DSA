#include <iostream>
#include <cstring>

using namespace std;

struct Student{
    string code;
    string name;
    string school;

    Student* next;
    Student(string code, string name, string school){
    this->code = code;
    this->name = name;
    this->school = school;
    next = nullptr;
    }
};

void displayStudents(Student* head){
    Student* current = head;
    while(current != NULL){
        cout << "Code: "<<current->code << " Name: " << current->name << " School Name: "<<current->school << endl;
        current = current->next;
    }
     cout << "End" << endl;
}

Student* addAtBeggining(Student* head,string code,string name,string school){

    Student* newStd = new Student(code,name,school);
    if(head == nullptr){
        head = newStd;
    }
    newStd->next = head;
    
    return newStd;

}

Student* addAtTheEnd(Student* head,string code,string name,string school){
       Student* newStd = new Student(code,name,school);
         
        if (head == nullptr) {
        return newStd;
    } 

        Student* current = head;
       while(current->next != nullptr){
        current = current->next;
       }
       current->next = newStd;
       newStd->next = nullptr;
   
   return newStd;
}

int main(){
 
    Student* student1 = new Student("RCA3423","Baba","RCA");
     Student* student2 = new Student("RCA4423","Emmy","GSSA");
      Student* student3 = new Student("RCA3723","Anna","GSSR");
       Student* student4 = new Student("RCA3223","Kelly","GSOB");
        Student* student5 = new Student("RCA3823","Mary","ESB");

    student1->next = student2;
    student2->next = student3;
    student3->next = student4;
    student4->next = student5;
    student5->next = nullptr;

    student1 = addAtBeggining(student1,"RCA44534","Kaliza","RCA");
    displayStudents(student1);
    student5 = addAtTheEnd(student1,"RCA438745","Esther","RCA");
    displayStudents(student1);
    

    return 0;
}