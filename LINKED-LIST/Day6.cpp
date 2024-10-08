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

    return 0;
}

// Sort a Linked List

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

Node* MergeSll(Node* list1,Node* list2){
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(list1!= nullptr && list2 != nullptr){
        if(list1->data <= list2->data){
            temp->next = list1;
            list1 = list1->next;
        }else{
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if(list1 != nullptr){
        temp->next = list1;
    }else{
        temp->next = list2;
    }

    return dummyNode->next;
}

Node* FindMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* Sll(Node* head){
    if(head == nullptr || head->next == nullptr) return head;
    Node* mid = FindMiddle(head);
    Node* right = mid->next;
    mid->next = nullptr;
    Node* left = head;

    left = Sll(left);
    right = Sll(right);

    return MergeSll(left,right);
}

void printLinkedList(Node* head){
    while(head != nullptr){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Linked List: 3 2 5 4 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head =  Sll(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}

// Sort a linked list of 0s, 1s and 2s

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
Node *segregate(Node *head)
{

    // Add code here
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            cnt0++;
        };
        if (temp->data == 1)
        {
            cnt1++;
        };
        if (temp->data == 2)
        {
            cnt2++;
        };
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr)
    {
        if (cnt0 > 0)
        {
            cnt0--;
            temp->data = 0;
        }
        else if (cnt1 > 0)
        {
            cnt1--;
            temp->data = 1;
        }
        else
        {
            cnt2--;
            temp->data = 2;
        }
        temp = temp->next;
    }
    return head;
}
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(0);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = segregate(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}
