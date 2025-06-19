#include <iostream>

using namespace std;

struct Stack {
    int *arr;
    int capacity;
    int nextIndex;

    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
        } else {
            arr[nextIndex] = val;
            nextIndex++;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
        } else {
            nextIndex--;
        }
    }

    bool isEmpty() {
        return nextIndex == 0;
    }

    bool isFull() {
        return nextIndex == capacity;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[nextIndex - 1];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = nextIndex - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack *myStack = new Stack(5);

    cout << "Start adding elements " << endl;

    myStack->push(10);
    myStack->push(20);
    myStack->push(30);
    myStack->push(40);
    myStack->push(50);
    myStack->push(60); 

    myStack->display();

    cout << "The top element in myStack is: " << myStack->peek() << endl;
    myStack->pop();
    myStack->pop();

    cout << "After removing elements"<<endl;
    myStack->display();

    cout << "The top element in myStack is: " << myStack->peek() << endl;

    myStack->pop();
    myStack->pop();
    myStack->pop();
    myStack->pop(); // Should display "Stack Underflow"

    delete myStack; // Free dynamically allocated memory

    return 0;
}
