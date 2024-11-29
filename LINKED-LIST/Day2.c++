// DOUBLY LINKED LIST 

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int val, Node* prevNode = nullptr, Node* nextNode = nullptr) {
        data = val;
        prev = prevNode;
        next = nextNode;
    }
};

// convert arr to doubly linked list 
Node* convertoDll(vector<int> arr,int n){
    Node* head = new Node(arr[0]);
    Node* pre = head;
    
    for(int i = 1; i < n; i++) {
        Node* temp = new Node(arr[i], pre, nullptr);
        pre->next = temp;
        pre = temp;
    }
    return head;
}



void print(Node* head){
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// deletion
// 1.delete_at_beginning
Node* delete_at_beginning(Node*& head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

// 2.delete_at_end
Node* delete_at_end(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newTail = temp->prev;
    newTail->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

// 3.delete_at_position
Node* delete_at_position(Node* head,int pos){
    int cnt = 0;
    Node* temp = head;
    while(temp != 0){
        cnt++;
        if(cnt == pos) break;
        temp = temp->next;
    }
    Node* pre = temp->prev;
    Node* front = temp->next;
    if(pre == nullptr && front == nullptr){
        delete temp;
        return nullptr;
    }else if(pre == nullptr){
        delete_at_beginning(head);
        return head;
    }else if(front == nullptr){
        delete_at_end(head);
        return head;
    }else{
        pre->next = front;
        front->prev = pre;
        delete temp;
        return head;
    }


}



// Insertion
// 1.insert_at_beginning
void insert_at_head(Node*& head,int data){
    Node* nptr = new Node(data,nullptr, head);
    head->prev = nptr;
    head = nptr;
}


// 2. inset_at_end
void insert_at_end(Node*& head, int data){
    Node* nptr = new Node(data);
    if(head == nullptr){
        head = nptr;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = nptr;
    nptr->prev = temp;
}

// insert at_any_position
void at_any_position(Node*& head, int data, int pos) {
    // Create a new node
    Node* nptr = new Node(data);

    // Special case: insert at the head
    if (pos == 1) {
        nptr->next = head;
        if (head != nullptr) {
            head->prev = nptr;
        }
        head = nptr;
        return;
    }

    // Traverse to the position
    Node* temp = head;
    int cnt = 1;

    // Traverse until position or end of the list
    while (temp != nullptr && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    // If position is greater than the list length
    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        delete nptr; // Prevent memory leak
        return;
    }

    // Insert in the middle or at the end
    nptr->next = temp->next;
    nptr->prev = temp;

    if (temp->next != nullptr) { // If not inserting at the end
        temp->next->prev = nptr;
    }
    temp->next = nptr;
}




int main() {
    int n = 5;
    vector<int> arr = {1, 2, 3, 4, 5};
    
    Node* head = convertoDll(arr,n);
    print(head);
    // head = delete_at_beginning(head);
    cout << "Affer delete first node in doubly linked list: ";
    print(head);
    cout << head->prev;
    cout << head->next;
    head = delete_at_end(head);
    print(head);
    cout << "Enter the position of node with you want to delete " << endl;
    int pos;
    cin >> pos;
    head = delete_at_position(head,pos);
    print(head);
    int data, pos;
    cout << "enter the value: " << endl;
    cin >> data;
    cin >> pos;
    insert_at_head(head,data);
    insert_at_end(head,data);
    at_any_position(head,data,pos);
    return 0;
}
