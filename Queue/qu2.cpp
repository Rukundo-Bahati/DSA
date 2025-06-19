#include <iostream>
using namespace std;

// int queue[100], n = 100, front = -1, rear = -1,size;
struct Queue {
   int front,rear,n;
   int *queue;
   
   Queue(int c){
    front = rear= -1;
    n=c;
    queue = new int[n];
   }


void enqueue() {
    int val;
    if (rear == n - 1) {
        cout << "Queue Overflow/Full" << endl;
    } else {
        cout << "Insert the element in the queue: ";
        cin >> val;
        if (front == -1) { // If the queue is initially empty
            front = 0;
        }
        rear++;
        queue[rear] = val;
        cout << "Inserted " << val << " into the queue." << endl;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow/Empty" << endl;
        return;
    }
    cout << "Element deleted from queue is: " << queue[front] << endl;
    front++;
    if (front > rear) { // Reset the queue when it's empty
        front = -1;
        rear = -1;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

void readFront() {
    if (front == -1) {
        cout << "Queue underflow" << endl;
        return;
    }
    cout << "Element at the front is: " << queue[front] << endl;
}
};

int main() {
    int ch;
    Queue q(5);

    cout << "1) Insert element to queue" << endl;
    cout << "2) Delete element from queue" << endl;
    cout << "3) Display all the elements of the queue" << endl;
    cout << "4) Read element from the front of the queue" << endl;
    cout << "5) Exit" << endl;

    do {
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.readFront();
                break;
            case 5:
                cout << "Exited the Queue" << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }
    } while (ch >0 && ch< 5);

    return 0;
}
