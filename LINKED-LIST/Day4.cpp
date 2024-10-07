// // Detect a Cycle in a Linked List


// #include <bits/stdc++.h>
// using namespace std;

// class Node {
// public:
//     int data;        
//     Node* next;      

//     Node(int data1, Node* next1) {
//         data = data1;
//         next = next1;
//     }

    
//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//     }
// };

// // Broute force approach
// bool detectLoop(Node* head){
//     Node *temp = head;
//     unordered_map<Node*,int> mpp;
//     while(temp != nullptr){
//         if(mpp.find(temp)!= mpp.end()){
//             return true;
//         }

//         mpp[temp] = 1;
//     }
//     return false;
// }

// // Optimal Approach
// bool detectLoop(Node* head){
//     Node* slow = head;
//     Node* fast = head;
//     while (fast != nullptr && slow != nullptr)
//     {
//        fast = fast->next->next;
//        slow = slow->next;
//        if(slow == fast){
//         return true;
//        }
//     }
//     return false;
    
// }


// int main() {

    
//     Node* head = new Node(1);
//     Node* second = new Node(2);
//     Node* third = new Node(3);
//     Node* fourth = new Node(4);
//     Node* fifth = new Node(5);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = third; 
//     if (detectLoop(head)) {
//         cout << "Loop detected in the linked list." << endl;
//     } else {
//         cout << "No loop detected in the linked list." << endl;
//     }

//     // Clean up memory (free the allocated nodes)
//     delete head;
//     delete second;
//     delete third;
//     delete fourth;
//     delete fifth;
//     return 0;
// }



// // Starting point of loop in a Linked List


// #include <iostream>
// #include <unordered_map>

// using namespace std;

// class Node {
// public:
//     int data;      
//     Node* next;

//     Node(int data1, Node* next1) {
//         data = data1;
//         next = next1;
//     }

//     Node(int data1) {
//         data = data1;
//         next = nullptr;
//     }
// };


// Broute force approach
// Node* detectLoop(Node* head) {
//     Node* temp = head;
//     unordered_map<Node*, int> mp;

//     while(temp != NULL) {
//         if(mp.count(temp) != 0) {
//             return temp;
//         }
//         mp[temp] = 1;
//         temp = temp->next;
//     }

//     return nullptr;
// }



// Optimal approach
// Node* firstNode(Node* head) {
//     Node* slow = head;  
//     Node* fast = head;  

//     while (fast != NULL && fast->next != NULL) {
//         slow = slow->next;        
//         fast = fast->next->next;  

//         if (slow == fast) {
//             slow = head; 

//             while (slow != fast) {
//                 slow = slow->next;  
//                 fast = fast->next;  
//             }
//             return slow;  
//         }
//     }
//     return NULL; 
// }



// int main() {
//     Node* node1 = new Node(1);
//     Node* node2 = new Node(2);
//     node1-> next = node2;
//     Node* node3 = new Node(3);
//     node2-> next = node3;
//     Node* node4 = new Node(4);
//     node3->next = node4;
//     Node* node5 = new Node(5);
//     node4-> next = node5;

//     node5->next = node2;

//     Node* head = node1;

//     Node* loopStartNode = firstNode(head);

//     if (loopStartNode) {
//         cout << "Loop detected. Starting node of the loop is: "<< loopStartNode->data << endl;
//     } else {
//         cout << "No loop detected in the linked list." << endl;
//     }

//     return 0;
// }



// Length of Loop in Linked List

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
// Broute Force 
// int lengthOfLoop(Node* head) {
//     Node* temp = head;
//     unordered_map<Node*, int> mpp;
//     int count = 0;
    
//     while (temp != nullptr) {
//         if (mpp.find(temp) != mpp.end()) {
//             return count - mpp[temp];
//         }
//         mpp[temp] = count;
//         temp = temp->next;
//         count++;
//     }
    
//     return 0;
// }


// Optical approach
int length(Node* slow, Node* fast){
    int count = 1;
    while(slow != fast){
        count++;
        fast = fast->next;
    }

    return count++;

}
int lengthOfLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
     while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return length(slow,fast);
        }
     }
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; 

    int loopLength = lengthOfLoop(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
}




