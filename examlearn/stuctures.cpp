#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List operations
void linkedListOperations() {
    Node* head = nullptr;
    vector<int> values;
    
    // Add 4 nodes
    for (int i = 1; i <= 4; i++) {
        int val;
        cout << "Enter value for node " << i << ": ";
        cin >> val;
        values.push_back(val);
        
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    // Display linked list after adding elements
    cout << "Linked list after adding 4 elements: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    // Sort the values
    sort(values.begin(), values.end());
    
    // Rebuild the linked list with sorted values (excluding last element)
    head = nullptr;
    for (int i = 0; i < values.size() - 1; i++) {
        Node* newNode = new Node(values[i]);
        newNode->next = head;
        head = newNode;
    }
    
    // Display final linked list
    cout << "Linked list after sorting its elements and deletion of the last element: ";
    temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    
    // Clean up memory
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

// Stack operations
void stackOperations() {
    const int MAX_SIZE = 5;
    int stack[MAX_SIZE];
    int top = -1;
    
    // Push 5 elements
    for (int i = 0; i < MAX_SIZE; i++) {
        int val;
        cout << "Enter value to push onto stack: ";
        cin >> val;
        
        if (top == MAX_SIZE - 1) {
            cout << "Stack is full!" << endl;
            break;
        }
        stack[++top] = val;
    }
    
    // Pop one element
    if (top == -1) {
        cout << "Stack is empty!" << endl;
    } else {
        top--;
    }
    
    // Display stack elements
    cout << "Stack elements after 5 pushing and 1 pop operations: ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// Queue operations
void queueOperations() {
    const int MAX_SIZE = 5;
    int queue[MAX_SIZE];
    int front = 0, rear = -1;
    int count = 0;
    
    // Enqueue 5 elements
    for (int i = 0; i < MAX_SIZE; i++) {
        int val;
        cout << "Enter value to add to queue: ";
        cin >> val;
        
        if (count == MAX_SIZE) {
            cout << "Queue is full!" << endl;
            break;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = val;
        count++;
    }
    
    // Dequeue one element
    if (count == 0) {
        cout << "Queue is empty!" << endl;
    } else {
        front = (front + 1) % MAX_SIZE;
        count--;
    }
    
    // Display queue elements
    cout << "Queue elements after 5 enqueue and 1 dequeue operations: ";
    for (int i = 0; i < count; i++) {
        cout << queue[(front + i) % MAX_SIZE] << " ";
    }
    cout << endl;
}

int main() {
    int choice;
    
    do {
        cout << "Enter your choice:\n";
        cout << "1. Operate on Linked List\n";
        cout << "2. Operate on Stack\n";
        cout << "3. Operate on Queue\n";
        cout << "0. Exit\n\n";
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                linkedListOperations();
                break;
            case 2:
                stackOperations();
                break;
            case 3:
                queueOperations();
                break;
            case 0:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
        cout << endl;
    } while (choice != 0);
    
    return 0;
}