#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

// Function to display the linked list
void displayNode(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << "->";
        current = current->next;
    }
    cout << "End" << endl;
}

// Function to delete the first node of the linked list
Node* deleteBeginning(Node* head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete at the beginning!" << endl;
        return nullptr;
    }
    Node* temp = head;
    head = head->next;
    delete temp; 
    return head;
}

Node* deleteNode(Node* head, int i) {
    if (i < 0) {
        return head;
    }

    if (i == 0 && head) {
        Node* newHead = head->next; 
        delete head; 
        return newHead;  
    }

    Node* current = head;
    int count = 0;

    while (current != NULL && count < i - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL || current->next == NULL) {
        return head;
    }

    
    Node* temp = current->next;  
    current->next = current->next->next; 
    delete temp;  
    return head;
}


Node* reverse(Node* head) {
    Node* prev = nullptr; 
    Node* curr = head;  
    Node* next = nullptr; 

    while (curr != nullptr) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;       
        curr = next;      
    }

    return prev;
}

Node* deleteEnd(Node* head) {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete at the end!" << endl;
        return nullptr;
    }
    if (head->next == nullptr) {
        // If the list has only one node
        delete head;
        return nullptr;
    }
    Node* current = head;
    while (current->next->next != nullptr) {
        current = current->next;
    }
   
    delete current->next; 
    current->next = nullptr;
    return head;
}

Node* merge(Node* a, Node* b){
    if(a ==NULL)
     return b;
    if(b == NULL)
     return a;

     Node* c;
     if(a->data < b->data){
        c =a ;
        c->next = merge(a->next, b);
     } else{
        c=b;
        c->next = merge(a,b->next);
     }
     return c;
}

Node* mid_point(Node*head){
    if(head ==NULL || head->next == NULL)
      return head;

     Node* fast = head;
     Node* slow = head;
     while(fast != NULL && fast->next != NULL){
        fast = fast->next;
        if(fast->next ==NULL)
            break;
        
        fast = fast->next;
        slow = slow->next;
     } 
     return slow;
}

Node* merge_sort(Node* head){
    if(head==NULL && head->next == NULL)
     return head;

    Node* mid = mid_point(head);
    Node* a = head;
    Node* b = mid->next;

    mid->next = NULL;

    a = merge_sort(a);
    b = merge_sort(b);
    Node* c = merge(a,b);

    return c; 
}

int main() {
    // Create nodes
    Node* head = new Node(50);
    Node* second = new Node(10);
    Node* third = new Node(35);
    Node* fourth = new Node(20);
    Node* fifth = new Node(40);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Display the original list
    cout << "Original List:" << endl;
    displayNode(head);

    // Delete the first node
    head = deleteBeginning(head);
    cout << "List after deleting the first node:" << endl;
    displayNode(head);

    // Delete the last node
    head = deleteEnd(head);
    cout << "List after deleting the last node:" << endl;
    displayNode(head);

     cout << "Reversed List:" << endl;
    displayNode(head);


    return 0;
}
