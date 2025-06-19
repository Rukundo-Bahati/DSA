#include <iostream>

using namespace std;

int queue[100], n=100,front=-1,rear=-1;

void enqueue(int val){
    if(rear == n-1){
     cout << "The queue is full."<<endl;
    }  else {
        if(front == -1){
            front=0;
        } 
        rear++;
        queue[rear] = val;
    }
}

void dequeue(){
    if(front == -1 | front > rear){
        cout << "The Queue is empty."<<endl;
    } else {
        cout << "The removed front is "<<queue[front]<<endl;
        front++;
    }
}

//getting the front element
int peek(){
   if(front == -1 | front > rear){
    cout << "The queue is empty"<<endl;
    return 0;
   } else {
    return queue[front];
   }
}

void display(){
      if(front == -1 | front > rear){
        cout << "The Queue is empty."<<endl;
    } else {
        for(int i=front; i<=rear;i++){
            cout << "The element at front= "<<i << " is "<<queue[i]<<endl;
        }
    }
}

int main(){
 
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  
  display();

  dequeue();
  dequeue();
  
  display();

    return 0;
}