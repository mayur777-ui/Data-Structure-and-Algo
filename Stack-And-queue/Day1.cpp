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

// IMPLEMENTATION OF STACK USING IN-BUILT QUEUE;
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue <int> q;
    public:
    void Push(int data){
        int s = q.size();
        q.push(data);
        for(int i = 0; i < s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int temp = q.front();
        q.pop();
        return temp;
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }
     bool isEmpty() {
        return q.empty();
    }
};


int main() {
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);

    cout << "Top element: " << s.top() << endl;  
    cout << "Popped element: " << s.pop() << endl; 
    cout << "Popped element: " << s.pop() << endl; 
    cout << "Top element: " << s.top() << endl;

    return 0;
}



// IMPLEMENTATION Queue using In-Built Stack
#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int x = s1.top();
        s1.pop();
        return x;
    }

    int front() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Popped element: " << q.pop() << endl;
    cout << "Front element after pop: " << q.front() << endl;

    return 0;
}

// APPROACH 2.
#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> input;
    stack<int> output;

public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (!output.empty()) {
            int x = output.top();
            output.pop();
            return x;
        }
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        if (output.empty()) {
            throw runtime_error("Queue is empty!");
        }
        int x = output.top();
        output.pop();
        return x;
    }

    int top() {
        if (!output.empty()) {
            return output.top();
        }
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
        if (output.empty()) {
            throw runtime_error("Queue is empty!");
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};

int main() {
    Queue* q = new Queue();

    // Testing the queue operations
    q->push(10);
    q->push(20);
    q->push(30);

    cout << "Front element: " << q->top() << endl;
    cout << "Popped element: " << q->pop() << endl; 
    cout << "Front element after pop: " << q->top() << endl; 

    q->push(40);
    cout << "Front element after pushing 40: " << q->top() << endl;
    cout << "Popped element: " << q->pop() << endl; 
    cout << "Is the queue empty? " << (q->empty() ? "Yes" : "No") << endl; 
    cout << "Popped element: " << q->pop() << endl; 
    cout << "Popped element: " << q->pop() << endl; 

    cout << "Is the queue empty now? " << (q->empty() ? "Yes" : "No") << endl; 
    
    delete q;

    return 0;
}
