#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;  // Make sure next is a pointer to Node
    Node() {
        next = NULL;  // Initialize next to NULL
    }
    Node(int d) {
        data = d;
        next = NULL;  // Initialize next to NULL
    }
};

void display(Node *head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node *n1 = new Node(10);  
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    display(n1);  // Display the linked list
}
