// Find intersection of Two Linked Lists

#include<iostream>

using namespace std;

class Node {
    public:
        int num;
        Node* next;
        Node(int val) {
            num = val;
            next = NULL;
        }
};

void appendNode(Node* &head, int val) {
    Node* newNode = new Node(val);
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    
    temp->next = newNode;
    return;
}


// Broute approach 
Node* findIntersection(Node* head1, Node* head2) {
    while (head2 != NULL) {
        Node* temp = head1;
        while (temp != NULL) {
            if (temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}


// Better approach
node* findIntersection(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;

}


// Optimal approach
node* findIntersection(node* head1,node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}






void displayList(Node* head) {
    while (head->next != NULL) {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main() {
    Node* head = NULL;
    appendNode(head, 1);
    appendNode(head, 3);
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 4);
    Node* head1 = head;
    head = head->next->next->next;
    Node* headSec = NULL;
    appendNode(headSec, 3);
    Node* head2 = headSec;
    headSec->next = head;
    
    cout << "List1: "; 
    displayList(head1);
    
    cout << "List2: "; 
    displayList(head2);
    
    Node* intersection = findIntersection(head1, head2);
    if (intersection == NULL) 
        cout << "No intersection\n";
    else 
        cout << "The intersection point is " << intersection->num << endl;
    
    return 0;
}



// Add two numbers represented as Linked Lists

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        while( (l1 != NULL || l2 != NULL) || carry) {
            int sum = 0; 
            if(l1 != NULL) {
                sum += l1->val; 
                l1 = l1 -> next; 
            }
            
            if(l2 != NULL) {
                sum += l2 -> val; 
                l2 = l2 -> next; 
            }
            
            sum += carry; 
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp -> next = node; 
            temp = temp -> next; 
        }
        return dummy -> next; 
    }
};

void printList(ListNode* node) {
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next != nullptr) {
            std::cout << " -> ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}


ListNode* createList(const std::vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int value : values) {
        ListNode* newNode = new ListNode(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

int main() {
    Solution solution;


    ListNode* l1 = createList({2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    ListNode* result = solution.addTwoNumbers(l1, l2);
    std::cout << "Result: ";
    printList(result);

   
    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }
    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
