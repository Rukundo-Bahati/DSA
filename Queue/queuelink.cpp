#include <iostream>

using namespace std;

class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        this->data = x;
        next = nullptr;
    }
};

class Queue {
    Node *head;
    Node *tail;
    int size;

  public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Queue()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(int ele) {
        Node *n = new Node(ele);
        if (head == nullptr) {
            head = n;
            tail = n;
        }

        else {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;

        if (size == 0) 
        {
            tail = nullptr;
        }
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return head->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.enqueue(70);

    cout << "Queue elements: "<<endl;
    q.display();
    cout << "Front: " << q.front() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << "Front after dequeue: " << q.front() << endl;
    cout << "Queue size: " << q.getSize() << endl;
    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(60);
    q.enqueue(70);
    q.display();

    q.dequeue();
    q.dequeue();
    cout << "Front: " << q.front() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    while (!q.isEmpty())
    {
        cout << "Dequeuing: " << q.front() << endl;
        q.dequeue();
    }
    
    cout << "Final size: " << q.getSize() << endl;
    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
