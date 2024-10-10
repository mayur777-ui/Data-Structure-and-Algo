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
