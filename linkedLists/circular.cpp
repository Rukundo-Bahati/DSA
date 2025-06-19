#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
  
    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node *insertInEmptyList(Node *last, int data){
    if (last != nullptr) return last;
    
    Node *newNode = new Node(data);
  
    newNode->next = newNode;
    last = newNode;
    return last;
}

void printList(Node* last){
    if(last == NULL) return;
  
    // Start from the head node
    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next) break;
    }
    cout << endl;
}

Node* insertAtBeginning(Node* last, int value){
   
    Node* newNode = new Node(value);

    if (last == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = last->next;
    last->next = newNode;

    return last;
}

Node *insertEnd(Node *tail, int value) {
    Node *newNode = new Node(value);

    if (tail == nullptr){
        tail = newNode;

        newNode->next = newNode;
    }
    else{

        newNode->next = tail->next;
        tail->next = newNode;

        tail = newNode;
    }
    return tail;
}

Node *insertAtPosition(Node *last, int data, int pos){

    if (last == nullptr){
        if (pos != 1){
            cout << "Invalid position!" << endl;
            return last;
        }
        Node *newNode = new Node(data);
        last = newNode;
        last->next = last;
        return last;
    }

    Node *newNode = new Node(data);
    Node *curr = last->next;

    if (pos == 1){
        // Insert at the beginning
        newNode->next = curr;
        last->next = newNode;
        return last;
    }

    for (int i = 1; i < pos - 1; ++i) {
        curr = curr->next;
      
        if (curr == last->next){
            cout << "Invalid position!" << endl;
            return last;
        }
    }
    newNode->next = curr->next;
    curr->next = newNode;

    // Update last if the new node is inserted at the end
    if (curr == last) last = newNode;

    return last;
}

Node* deleteFirstNode(Node* last) {
    if (last == nullptr) {
     
        cout << "List is empty" << endl;
        return nullptr;
    }

    Node* head = last->next;

    if (head == last) {
       
        delete head;
        last = nullptr;
    } else {
    
        last->next = head->next;
        delete head;
    }

    return last;
}

Node* deleteSpecificNode(Node* last, int key) {
    if (last == nullptr) {
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }

    Node* curr = last->next;
    Node* prev = last;

    // If the node to be deleted is the only node in the list
    if (curr == last && curr->data == key) {
        delete curr;
        last = nullptr;
        return last;
    }

    // If the node to be deleted is the first node
    if (curr->data == key) {
        last->next = curr->next;
        delete curr;
        return last;
    }

    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

 
    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        delete curr;
    } else {
      
        cout << "Node with data " << key
          << " not found." << endl;
    }

    return last;
}

Node* deleteLastNode(Node* last) {
    if (last == nullptr) {
        // If the list is empty
        cout << "List is empty, nothing to delete." << endl;
        return nullptr;
    }
    Node* head = last->next;

    if (head == last) {
        delete last;
        last = nullptr;
        return last;
    }
    // Traverse the list to find the second last node
    Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }

    curr->next = head;
    delete last;
    last = curr;

    return last;
}


bool search(Node* last, int key) {
    if (last == nullptr) {
        // If the list is empty
        return false;
    }

    Node* head = last->next;
    Node* curr = head;

    while (curr != last) {
        if (curr->data == key) {
            return true; 
        }
        curr = curr->next;
    }

    // Check the last node
    if (last->data == key) {
      // Key found
        return true; 
    }
    // Key not found
    return false; 
}


int main(){
Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    // Insert 5 at the beginning
    last = insertAtBeginning(last, 5);

    cout << "List after inserting 5 at the beginning: ";
    printList(last);

    last = insertEnd(last, 5);
    last = insertEnd(last, 6);

    cout << "List after inserting 5 and 6: ";
    printList(last);

     int data = 5, pos = 2;
    last = insertAtPosition(last, data, pos);
    cout << "List after insertions: ";
    printList(last);

    last = deleteFirstNode(last);
    cout << "List after deleting first node: ";
    printList(last);
  
     last = deleteLastNode(last);

    cout << "List after deleting last node: ";
    printList(last);

    int key = 3;
    last = deleteSpecificNode(last, key);

    cout << "List after deleting node " << key << ": ";
    printList(last);

     int keyToSearch = 5;
    bool found = search(last, keyToSearch);
    if (found) {
        cout << "Value " << keyToSearch << " found in the list." << endl;
    } else {
        cout << "Value " << keyToSearch << " not found in the list." << endl;
    }


    return 0;
}