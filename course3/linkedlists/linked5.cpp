#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;  
    Node() {
        next = NULL;  
    }
    Node(int d) {
        data = d;
        next = NULL; 
    }
};

void display(Node *head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

Node* insertHead(Node *head, int data) {
    Node *newNode = new Node(data); 
    newNode->next = head; 
    head = newNode;  
    
    return head;
}

int main() {
    Node *head = new Node(30);  
    head = insertHead(head, 10);  

    display(head);  
    
    return 0;
}
