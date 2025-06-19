#include <iostream>
using namespace std;

#define MAX 5

class Stack {
private:
    int items[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        items[++top] = value;
        cout << value << " pushed to the stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << items[top] << " popped from the stack." << endl;
        top--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top element: " << items[top] << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    while (true) {
        cout << "\nStack Menu:\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            s.peek();
            break;
        case 5:
            cout << "Exiting Stack Program." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}
