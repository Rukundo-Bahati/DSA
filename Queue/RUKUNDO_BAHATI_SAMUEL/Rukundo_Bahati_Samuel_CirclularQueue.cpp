#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularQueue {
private:
    Node* front;
    Node* rear;
    int size;

public:
    CircularQueue() {
        front = rear = nullptr;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue from an empty queue." << endl;
            return;
        }
        if (front == rear) { // Only one element
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
        }
        size--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty, no front element!" << endl;
            return -1;
        }
        return front->data;
    }

    int getSize() {
        return size;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != front);
        cout << "(front)" << endl;
    }

    ~CircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    CircularQueue cq;

    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    
    cq.display();
    cout << "Front element: " << cq.peek() << endl;
    cout << "Queue size: " << cq.getSize() << endl;

    cq.dequeue();
    cq.display();
    
    cq.dequeue();
    cq.dequeue();
    cq.dequeue(); // Extra dequeue to check underflow

    return 0;
}
