// Delete the Middle Node of the Linked List


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



// Broutel force
Node* deleteMiddle(Node* head) {
    Node* temp = head;
    int n = 0;
    
    while(temp != nullptr) {
        n++;
        temp = temp->next;
    }

    int res = n / 2;
    temp = head;

    while(temp != nullptr) {
        res--;
        if (res == 0) {
            Node* middle = temp->next;
            temp->next = temp->next->next;
            free(middle);
            break;
        }
        temp = temp->next;
    }

    return head;
}




// Optimal Approach
Node* deleteMiddle(Node* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head->next->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    return head;
}


void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original Linked List: ";
    printLL(head);

    head = deleteMiddle(head);

    cout << "Updated Linked List: ";
    printLL(head);

}





