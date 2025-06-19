#include <iostream>

using namespace std;

// int queue[100], n=100,front=-1,rear=-1;

struct Queue{

    int front;
    int rear;
    int capacity;
    int *queue;
    
    Queue (int cap){
        capacity = cap;
        front = rear= -1;
        queue=new int[capacity];
    }

    ~Queue(){
     delete[] queue;   
    }
    

void enqueue(int val){
    if(rear == capacity-1){
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
};
int main(){
 
  Queue q(5);
  
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  q.enqueue(40);
  q.enqueue(50);
  
  q.display();

  q.dequeue();
  q.dequeue();
  
  q.display();
  cout << "The front element is: " << q.peek();

    return 0;
}