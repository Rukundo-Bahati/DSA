#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int items[MAX];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        if (front == -1) front = 0;
        rear++;
        items[rear] = value;
        cout << value << " added to the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << items[front] << " removed from the queue." << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << items[i] << " ";
        }
        cout << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << items[front] << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Menu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            q.peek();
            break;
        case 5:
            cout << "Exiting Queue Program." << endl;
            return 0;
        default:
            cout << "Invalid choice." << endl;
        }
    }
}
