#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    public:
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

Node *head = NULL;

Node* insertHead(Node *head, int data) {
    Node *newNode = new Node(data); 
    newNode->next = head; 
    head = newNode;  
    
    return head;
}

void addFirst(Node **head,int val){
    Node *newNode = new Node(val);
    newNode->next = *head;
    *head = newNode;
}

void display(Node *head) {
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main() {

    Node* root = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    
    root->next=second;
    second->next=third;
    head=root;
    addFirst(&head,20);
    addFirst(&head,30);
    display(head);

    return 0;
}
