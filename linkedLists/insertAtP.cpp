#include <iostream>

using namespace std;

class ListNode {
  public:
  int val;
  ListNode * next;
  ListNode(int x) {
    val = x;
    next = nullptr;
  }
};

ListNode * head, * tail;

void PrintList() {
  ListNode * curr = head;
  for (; curr != nullptr; curr = curr -> next)
    cout << curr -> val << "-->";
  cout << "null" << endl;
}

void InsertatLast(int value){ // Function for creating a LinkedList{

  ListNode * newnode = new ListNode(value);
  if (head == nullptr)
    head = newnode, tail = newnode;
  else
    tail = tail -> next = newnode;
}

int Length() {
  int len = 0;
  for (ListNode * curr = head; curr != nullptr; curr = curr -> next)
    len++;
  return len;
}

void InsertatPositon(int value, int pos) {

  ListNode * newnode = new ListNode(value);

  int len = Length();

  if (pos <= len) {
    if (pos == 0) {
      newnode -> next = head;
      head = newnode;
    } else {
      ListNode * curr = head;
      while (--pos)
        curr = curr -> next;
      newnode -> next = curr -> next;
      curr -> next = newnode;
    }
  } else
    cout << "Invalid Positon" << endl;
}

int main() {
  InsertatLast(10);
  InsertatLast(20);
  InsertatLast(30);
  InsertatLast(40);
  cout << "Intial LinkedList : " << endl;
  PrintList();
  InsertatPositon(90, 3);
  cout << "LinkedList after Inserting node, with value 90, at position 3 : " 
  << endl;
  PrintList();
  InsertatPositon(100, 0);
  cout << "LinkedList after Inserting node, with value 100, at position 0 : " 
  << endl;
  PrintList();
  return 0;
}

