// IMPLEMENTATION OF STACK USING ARRAY
#include<bits/stdc++.h>
using namespace std;

class Stack{
    int top;
    int *arr;
    int size;
    public:
        Stack(){
            top = -1;
            size = 1000;
            arr = new int[size];
        }
        void push(int data){
            top++;
            arr[top] = data;
        }
        int pop() {
            int x = arr[top];
            top--;
            return x;
        }
        int Top(){
            return arr[top];
        }
        int Size(){
            return top+1;
        }
};


int main() {

  Stack s;
  s.push(6);
  s.push(3);
  s.push(7);
  cout << "Top of stack is before deleting any element " << s.Top() << endl;
  cout << "Size of stack before deleting any element " << s.Size() << endl;
  cout << "The element deleted is " << s.pop() << endl;
  cout << "Size of stack after deleting an element " << s.Size() << endl;
  cout << "Top of stack after deleting an element " << s.Top() << endl;
  return 0;
}




// IMPLEMENTATION OF QUEUE BY Array 
#include<iostream>
using namespace std;

class Queue{
  int * arr;
  int start, end, currSize, maxSize;
  public:
    Queue() {
      arr = new int[16];
      start = -1;
      end = -1;
      currSize = 0;
    }

    
    Queue(int maxSize) {
        // ( * this).maxSize = maxSize;
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    void push(int x){
        if(currSize == maxSize) {
            cout << "Queue is full" << endl;
            return;
        }
        if(end == -1){
            start  = 0;
            end = 0;
        }else{
            end = (end+1)%maxSize;
        }
        arr[end] = x;
        currSize++;
    }

    int pop(){
        if (start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int a = arr[start];
        if(currSize == 1){
            start = -1;
            end = -1;
        }else{
            start = (start + 1)%maxSize;
        }
        currSize--;
        return a;
    }

    int top(){
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    int size() {
    return currSize;
  }
};


int main() {
  Queue q(6);
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);
  cout << "The peek of the queue before deleting any element " << q.top() << endl;
  cout << "The size of the queue before deletion " << q.size() << endl;
  cout << "The first element to be deleted " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element " << q.top() << endl;
  cout << "The size of the queue after deleting an element " << q.size() << endl;

  return 0;
}





// IMPLEMENTATION OF STACK BY Linked list 
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int value){
            data = value;
            next = NULL;
        }
};

class Stack{
    public:
        Node* top;
        int size;
        Stack(){
            top = nullptr;
            size = 0;
        }

        void push(int x){
            Node* newNode = new Node(x);
            newNode->next = top;
            top = newNode;
            size++;
        }

        int pop(){
            if(top == NULL){
                return -1;
            }
            int popped = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
            return popped;
        }

        int Top(){
            if(top == nullptr){
                return -1;
            }
            return top->data;
        }

        bool isEmpty(){
            return top == nullptr;
        }

        int Size(){ 
            return size;
        }

        void printStack(){
            Node* temp = top;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
  Stack s; 
  s.push(10);
  s.push(20);
  s.push(30);

  cout << "Element popped: " << s.pop() << "\n";
  cout << "Stack size: " << s.Size() << "\n";
  cout << "Stack empty or not? " << (s.isEmpty() ? "Yes" : "No") << "\n";
  cout << "Stack's top element: " << s.Top() << "\n";
  cout << "Stack elements: ";
  s.printStack();

  return 0;
}




// IMPLEMENTATION OF QUEUE BY USING LINKED LIST
#include <iostream>
using namespace std;

struct Node
{
    int data = 0;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};


class Queue{
    int size;
    Node* front;
    Node* rear;
    public:
        Queue(){
            size = 0;
            front = nullptr;
            rear = nullptr;
        }

        bool empty(){
            return front == nullptr;
        }

        int  top(){
            return front->data;
        }

        void Enqueue(int x){
            if(front == nullptr){
                Node* nptr = new Node(x);
                front = nptr;
                rear = nptr;
                size++;
                return;
            }
            Node* nptr = new Node(x);
            rear->next = nptr;
            rear = nptr;
            size++;
            return;
        }

        int Dequeue(){
            if(front == nullptr){
                return -1;
            }
            int popped = front->data;
            Node* temp = front;
            front = front->next;
            delete temp;
            size--;
            return popped;
        }
        int Size(){
            return size;
        }
};




int main() {
    Queue q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    cout << "Front element: " << q.top() << "\n";  
    cout << "Dequeue: " << q.Dequeue() << "\n";   
    cout << "Front element after dequeue: " << q.top() << "\n";  

    cout << "Queue size: " << q.Size() << "\n";  

    return 0;
}


