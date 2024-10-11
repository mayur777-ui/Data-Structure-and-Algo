// Reverse Linked List in groups of Size K
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

Node* reverseLinkedList(Node *head)
{
   Node* temp = head;  
   Node* prev = NULL;  
   
   while(temp != NULL){  
       Node* front = temp->next;  
       temp->next = prev;  
       prev = temp;  
       temp = front; 
   }
   
   return prev;  
}

Node* getKthNode(Node* temp, int k){
    k -= 1; 

    while(temp != NULL && k > 0){
        k--; 
        temp = temp -> next; 
    }
    
    return temp; 
}

Node* kReverse(Node* head, int k){
    Node* temp = head; 
    Node* prevLast = NULL; 
    
    while(temp != NULL){
        Node* kThNode = getKthNode(temp, k); 

        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp; 
            }
            break; 
        }
        
        Node* nextNode = kThNode -> next; 

        kThNode -> next = NULL; 

        reverseLinkedList(temp); 
        
        if(temp == head){
            head = kThNode;
        }else{
            prevLast -> next = kThNode; 
        }

        prevLast = temp; 

        temp = nextNode; 
    }
    
    return head; 
}

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = kReverse(head, 4);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}


// Roted Linked List
#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int num;
        node* next;
        node(int a) {
            num = a;
            next = NULL;
        }
};
void insertNode(node* &head,int val) {
    node* newNode = new node(val);
    if(head == NULL) {
        head = newNode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}



// BROUTE FORCE
node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}


// Optimal Approach
node* rotateRight(node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0){
        return head;
    }
    node* temp = head;
    int length = 1;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = head;
    k = k%length;
    int end = length - k;
    while (end--)
    {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = nullptr;
    return head;
}

void printList(node* head) {
    while(head->next != NULL) {
        cout<<head->num<<"->";
        head = head->next;
    } 
    cout<<head->num<<endl;
    return;
}

int main() {
    node* head = NULL;
    //inserting Node
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    
    cout<<"Original list: ";
    printList(head);
    
    int k = 2;
    node* newHead = rotateRight(head,k);
    cout<<"After "<<k<<" iterations: ";
    printList(newHead);
    return 0;
}