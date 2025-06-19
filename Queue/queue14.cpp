#include <iostream>

using namespace std;

template<typename T>

struct Queue {
    T *arr;
    int front;
    int rear;
    int capacity;
    int size;

    Queue() {
        capacity = 5;
        arr = new T[capacity];
        rear= 0;
        front = -1;
        size = 0;
    }

    ~Queue() {
        delete[] arr;
    }

 void enqueue(T ele){
          if(size == capacity){
            T *newArr = new T[2*capacity];
            int j = 0;
            for(int i=front;i<capacity;i++){
                newArr[j] = arr[i];
                j++;
            }
            front=0;
            rear = capacity;
            capacity = 2*capacity;
            delete []arr;
            arr = newArr;
          }
          
          arr[rear] = ele;
          rear=rear+1;
          if(front == -1){
            front = 0;
          }
          size++;
       }

    void dequeue() {
        if (front == -1) {
            cout << "The Queue is empty." << endl;
            return;
        } else {
            cout << "The deleted from queue is " << arr[front] << endl;
           for (int i = front; i < rear; i++){
              arr[i] = arr[i+1];
           }
            rear--;
            size--;
           
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "The queue is empty" << endl;
            return 0;
        }
        return arr[front];
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void display() {
        if (front == -1) {
            cout << "The Queue is empty." << endl;
        } else {
            cout << "Queue elements are: ";
            for (int i = front; i < rear; i++){
                cout << arr[i]<<" ";
            }
                cout << endl; 
        }
    }
};

int main() {
   
 Queue<int> q;

  cout << "Enqueueing elements:" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "Dequeuing two elements" << endl;
    q.dequeue();
    q.dequeue();

    cout << "Enqueueing more elements: 60, 70" << endl;
    q.enqueue(60);
    q.enqueue(70);

    q.display();

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.getSize() << endl;

 
    return 0;
}
