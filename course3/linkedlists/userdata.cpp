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

void print(Node *head){
    Node *temp= head;
    while (temp !=NULL)
    {
      cout <<temp->data<<"->";
      temp=temp->next;
    }

    cout << "NULL" <<endl;  
}

Node* userData() {
   int data;
   cout<<"Add number to LL or -1 to exit: "<<endl;
   cin>>data;
   Node *head= NULL;
   
   while(data != -1){
    Node *n = new Node(data);
    if(head == NULL){
        head = n;
    } else {
        n->next=head;
        head=n;
    }
    cin >> data;
   }
   return head;
}

int main() {
    Node *head = userData();  
    print(head); 
    
    return 0;
}
