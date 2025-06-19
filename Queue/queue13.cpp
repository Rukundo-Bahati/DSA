#include <iostream>

using namespace std;

struct Queue {
    int front;
    int rear;
    int capacity;
    int size;
    int *queue;

    Queue(int cap) {
        capacity = cap;
        front = rear = -1;
        size = 0;
        queue = new int[capacity];
    }

    ~Queue() {
        delete[] queue;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "The queue is full." << endl;
        } else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            queue[rear] = val;
            size++; 
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "The Queue is empty." << endl;
        } else {
            cout << "The removed front is " << queue[front] << endl;
            front++;
            size--; // Decrease size correctly
            if (front > rear) { 
                front = rear = -1;
                size = 0;
            }
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
            return 0;
        }
        return queue[front];
    }

    int count() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void display() {
        if (isEmpty()) {
            cout << "The Queue is empty." << endl;
        } else {
            for (int i = front; i <= rear; i++) {
                cout << "Element at index " << i << ": " << queue[i] << endl;
            }
        }
    }
};

int main() {
    Queue *q = new Queue(5);
    cout << "Adding elements: " << endl;
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);
    q->enqueue(60);
    q->enqueue(70); 
    cout << "End of addition of elements" << endl;
    q->display();

    q->dequeue();
    q->dequeue();
    cout<<"Adding other two elements"<<endl;
    q->enqueue(66);
    q->enqueue(77);
    cout<<"After adding other two elements"<<endl;
    q->display();
    
    cout << "The front element is: " << q->peek() << endl;
    cout << "The total number of elements in the queue is: " << q->count() << endl;

    return 0;
}
