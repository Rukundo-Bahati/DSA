#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node{newData, head};
    head = newNode;
}

void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node{newData, nullptr};
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node*& head, int key) {
    if (head == nullptr) return;

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;     
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next == nullptr) return;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == key) return true;
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);

    printList(head);

    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    printList(head);

    deleteNode(head, 20);
    printList(head);

    cout << "Search for 30: " << (search(head, 30) ? "Found" : "Not Found") << endl;

    return 0;
}
