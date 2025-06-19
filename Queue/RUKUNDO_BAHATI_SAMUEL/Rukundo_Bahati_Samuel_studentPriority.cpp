#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int code;
    string name;
    int age;
    Student* next;

    Student(int c, string n, int a) {
        code = c;
        name = n;
        age = a;
        next = nullptr;
    }
};

class PriorityQueue {
private:
    Student* head;

public:
    PriorityQueue() {
        head = nullptr;
    }

    void enqueue(int code, string name, int age) {
        Student* newStudent = new Student(code, name, age);
        if (!head || head->age > age) {
            newStudent->next = head;
            head = newStudent;
        } else {
            Student* temp = head;
            while (temp->next && temp->next->age <= age) {
                temp = temp->next;
            }
            newStudent->next = temp->next;
            temp->next = newStudent;
        }
    }

    void dequeue() {
        if (!head) {
            cout << "Queue is empty" << endl;
            return;
        }
        Student* temp = head;
        head = head->next;
        cout << "Removed: " << temp->name << " (Age: " << temp->age << ")" << endl;
        delete temp;
    }

    void display() {
        if (!head) {
            cout << "Queue is empty" << endl;
            return;
        }
        Student* temp = head;
        while (temp) {
            cout << temp->code << ": " << temp->name << " (Age: " << temp->age << ") -> ";
            temp = temp->next;
        }
        cout << "None" << endl;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    Student* peek() {
        if (!head) {
            cout << "Queue is empty" << endl;
            return nullptr;
        }
        return head;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    PriorityQueue pq;
    pq.enqueue(101, "Alice", 25);
    pq.enqueue(102, "Bob", 22);
    pq.enqueue(103, "Charlie", 27);
    pq.enqueue(104, "David", 20);
    pq.enqueue(105, "Eve", 30);

    cout << "Initial Queue:" << endl;
    pq.display();

    cout << "\nPeek at the front of the queue:" << endl;
    Student* front = pq.peek();
    if (front) {
        cout << "Front: " << front->name << " (Age: " << front->age << ")" << endl;
    }

    cout << "\nDequeue elements:" << endl;
    while (!pq.isEmpty()) {
        pq.dequeue();
        pq.display();
    }

    cout << "\nClear the queue:" << endl;
    pq.clear();
    pq.display();

    return 0;
}