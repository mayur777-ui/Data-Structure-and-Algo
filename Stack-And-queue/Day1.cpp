<<<<<<< HEAD
// IMPLEMENTATION OF STACK USING ARRAY
// #include<bits/stdc++.h>
// using namespace std;

// class Stack{
//     int top;
//     int *arr;
//     int size;
//     public:
//         Stack(){
//             top = -1;
//             size = 1000;
//             arr = new int[size];
//         }
//         void push(int data){
//             top++;
//             arr[top] = data;
//         }
//         int pop() {
//             int x = arr[top];
//             top--;
//             return x;
//         }
//         int Top(){
//             return arr[top];
//         }
//         int Size(){
//             return top+1;
//         }
// };


// int main() {

//   Stack s;
//   s.push(6);
//   s.push(3);
//   s.push(7);
//   cout << "Top of stack is before deleting any element " << s.Top() << endl;
//   cout << "Size of stack before deleting any element " << s.Size() << endl;
//   cout << "The element deleted is " << s.pop() << endl;
//   cout << "Size of stack after deleting an element " << s.Size() << endl;
//   cout << "Top of stack after deleting an element " << s.Top() << endl;
//   return 0;
// }




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
=======
// i am add
>>>>>>> 859d9dd101edcd1395257432ffa30415ae956359
