#include <iostream>
using namespace std;

#define MAX_SIZE 5  // Maximum size of the circular queue

class CircularQueue {
private:
    int items[MAX_SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Check if the queue is full
    bool isFull() {
        return count == MAX_SIZE;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Add an element to the queue (enqueue)
    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << element << endl;
            return;
        }
        
        rear = (rear + 1) % MAX_SIZE;
        items[rear] = element;
        count++;
        cout << "Enqueued " << element << endl;
    }

    // Remove an element from the queue (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        
        int element = items[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        cout << "Dequeued " << element << endl;
        return element;
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        
        cout << "Circular Queue elements: ";
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << items[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;

    // Test the circular queue
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cq.display();
    
    // Try to enqueue when full
    cq.enqueue(60);
    
    // Dequeue some elements
    cq.dequeue();
    cq.dequeue();
    cq.display();
    
    // Enqueue more elements (wrapping around)
    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();
    
    // Dequeue all elements
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.display();
    
    // Try to dequeue when empty
    cq.dequeue();

    return 0;
}