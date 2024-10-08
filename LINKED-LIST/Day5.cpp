// Check if the given Linked List is Palindrome

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





// // Broute force
// bool isPalindrome(Node* head){
//     Node* temp = head;
//     stack<int> s;
//     while(temp != nullptr){
//         s.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while (temp != nullptr)
//     {
//         if(temp->data != s.top()){
//             return false;
//         }

//         s.pop();
//         temp = temp->next;
//     }
    
// }

  




//Optical approach
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


Node*  funtomiddle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}


bool isPalindrom(Node* head){
     if(head == nullptr || head->next == nullptr){
        return true;
    }
    Node* temp = head;

    Node* middle = funtomiddle(head);
    Node* middle1 = reverseLinkedList(middle->next); 
    while(middle1 != nullptr){
        if(temp->data != middle1->data){
            return false;
        }

        temp = temp->next;
        middle1 = middle1->next;
    }
    return true;
}






int main() {
    
    Node* head = new Node(1);
    head->next = new Node(2);
    // head->next->next = new Node(2);
    // head->next->next->next = new Node(5);
    // head->next->next->next->next = new Node(1);



    if (isPalindrom(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}



