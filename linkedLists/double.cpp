#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void forwardTraversal(Node *head){
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->data << " "; // Added space to separate values
        current = current->next;      // Move to the next node
    }
    cout << endl;
}

void backwardTraversal(Node *tail)
{
    Node *currentNode = tail;
    while (currentNode != nullptr)
    {
        cout << currentNode->data << " "; // Added space to separate values
        currentNode = currentNode->prev;  // Move to the previous node
    }
    cout << endl;
}

int findLength(Node *head)
{
    int count = 0;
    for (Node *cur = head; cur != nullptr; cur = cur->next)
        count++;
    return count;
}

Node *insertBegin(Node *head, int data)
{
    Node *new_node = new Node(data);
    new_node->next = head;

    if (head != NULL)
    {
        head->prev = new_node;
    }
    return new_node;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node *insertEnd(Node *head, int new_data)
{

    Node *new_node = new Node(new_data);

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }

        curr->next = new_node;
        new_node->prev = curr;
    }

    return head;
}

Node *insertAtPosition(Node *head, int pos, int new_data)
{

    Node *new_node = new Node(new_data);

    // Insertion at the beginning
    if (pos == 1)
    {
        new_node->next = head;

        // If the linked list is not empty, set the prev
        // of head to new node
        if (head != NULL)
            head->prev = new_node;

        // Set the new node as the head of linked list
        head = new_node;
        return head;
    }

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; ++i)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Position is out of bounds." << endl;
        delete new_node;
        return head;
    }

    new_node->prev = curr;
    new_node->next = curr->next;
    curr->next = new_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;

    return head;
}

Node *delHead(Node *head)
{

    if (head == nullptr)
        return nullptr;

    // Store in temp for deletion later
    Node *temp = head;
    head = head->next;

    if (head != nullptr)
        head->prev = nullptr;

    delete temp;
    return head;
}

Node *delLast(Node *head)
{

    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;

    curr->prev->next = NULL;

    delete curr;
    return head;
}

Node *delPos(Node *head, int pos)
{

    if (!head)
        return head;

    Node *curr = head;

    for (int i = 1; curr && i < pos; ++i)
    {
        curr = curr->next;
    }

    if (!curr)
        return head;

    // Update the previous node's next pointer
    if (curr->prev)
        curr->prev->next = curr->next;

    // Update the next node's prev pointer
    if (curr->next)
        curr->next->prev = curr->prev;

    // If the node to be deleted is the head node
    if (head == curr)
        head = curr->next;

    // Deallocate memory for the deleted node
    delete curr;
    return head;
}

Node *searchNodeValue(Node *head, int value)
{
    if (!head)
    {
        cout << "The list is empty." << endl;
        return nullptr;
    }

    Node *current = head;
    int position = 1;

    // Traverse the list to search for the value
    while (current)
    {
        if (current->data == value)
        {
            cout << "Value " << value << " found at node " << position << "." << endl;
            return current; // Return the node where the value is found
        }
        current = current->next;
        position++;
    }

    // Value not found in the list
    cout << "Value " << value << " not found in the list." << endl;
    return nullptr;
}


int main()
{
    Node *head = new Node(1);
    Node *second = new Node(6);
    Node *third = new Node(3);

    head->next = second;
    second->next = third;
    third->next = nullptr;
    second->prev = head;
    third->prev = second;

    cout << "Forward Traversal:" << endl;
    forwardTraversal(head);

    cout << "Backward Traversal:" << endl;
    backwardTraversal(third);

    cout << "Length of the doubly linked list: " << findLength(head) << endl;

    cout << "Original Linked List: ";
    printList(head);

    // Insert a new node at the front of the list
    head = insertBegin(head, 0);

    // Print the updated list
    cout << "After inserting Node 1 at the front: ";
    printList(head);

    cout << "Inserting Node with data 4 at the end: ";
    int data = 4;
    head = insertEnd(head, data);

    // Print the updated list
    printList(head);

    cout << "Inserting Node with data 3 at position 3: ";
    int value = 8;
    int position = 3;
    head = insertAtPosition(head, position, value);

    // Print the updated list
    printList(head);

    printf("After Deletion at the beginning: ");
    head = delHead(head);

    printList(head);

    printf("After Deletion at the end: ");
    head = delLast(head);

    printList(head);

    cout << "After Deletion at the position 2: ";
    head = delPos(head, 2);

    printList(head);

    // Search and print value at the 2nd position
    int location = 6;
    searchNodeValue(head,location);
    

    return 0;
}
