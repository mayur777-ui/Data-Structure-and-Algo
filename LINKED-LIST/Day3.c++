// REVERSE Singaly Linked list
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;   
    Node* next;      
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


// 1 Broute froce approach

Node* reverse(Node* head){
    Node* temp = head;
    stack<int> s;
    while(temp != nullptr){
        s.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != nullptr){
        temp-> data = s.top();
        s.pop();
        temp = temp->next;
    }

    return head;
}





//Optimal approach
Node* reverse(Node* head){
    Node* temp = head;

    Node* prev = nullptr;
    while(temp != nullptr){
        Node* front = temp->next;

        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;   
}
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main(){

    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);


    cout << "Original Linked List: ";
    printLinkedList(head);

    head = reverse(head);


    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}


// Reverse Linked List in Groups of k
