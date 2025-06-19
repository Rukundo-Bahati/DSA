#include <iostream>
using namespace std;

class Student {
public:
    int code;
    string name;
    string school;
    int age;
    Student* next;

    Student(int c, string nm, int a, string sch) {
        code = c;
        name = nm;
        school = sch;
        age = a;
        next = NULL;
    }
};

void display(Student* head) {
    while (head != NULL) {
        cout << head->code << " " << head->name << " " << head->age << " y.old " << head->school << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Student* n1 = new Student(101, "Divine", 12, "RCA");
    Student* n2 = new Student(102, "Divine", 15, "RCA");
    Student* n3 = new Student(103, "Divine", 16, "RCA");
    Student* n4 = new Student(104, "Divine", 18, "RCA");

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    display(n1);

    return 0;
}
