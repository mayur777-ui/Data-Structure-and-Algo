// SINGLY LINKED LIST 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};


void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// INSERTION
// 1. insert_at_beginning

void insert_at_beginning(Node*& head,int data){
    Node* nptr = new Node();
    nptr->data = data;
    nptr->next = head;
    head = nptr;
}


// 2. insert_at_end
void insert_at_end(Node*& head, int data){
    Node*nptr = new Node();
    nptr->data = data;
    nptr->next = nullptr;
    if(head == nullptr){
        head = nptr;
    }else{
        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next; 
        }
        temp->next = nptr;
    }
}

//3. INSERT AT_ANY POSITION 

void insert_at_any_pos(Node*& head, int data,int pos){
    Node* nptr = new Node();
    nptr->data = data;
     if (pos < 1) {
        cout << "Invalid position" << endl;
        delete nptr; 
        return;
    }
    if(pos == 1){
        insert_at_beginning(head,data);
    }else{
        Node* temp = head;
        int cnt  = 1;
        while (temp != nullptr && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        cout << "Position out of range" << endl;
        delete nptr; 
        return;
    }
    nptr->next = temp->next;
    temp->next = nptr;
}
}

//deleteing
// 1.delete_at_beginning
void delete_at_beginning(Node*&head){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
// 2.delete_at_end
void delete_at_end(Node* head){
    if(head == nullptr){
        cout << "List is empty" << endl;
        return;
    }
    if(head->next == nullptr){
        Node* temp = head;
        head = nullptr;
        delete temp;
        return;
    }else{
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        Node* lastNode = temp->next;
        temp->next = nullptr;
        delete lastNode;
    }
}
// 3.delete_at_any_position
Node* deletion_at_pos(Node* head, int pos) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return head;
    }

    if (pos < 1) {
        cout << "Position is invalid." << endl;
        return head;
    }

    // Handle deletion of the first node
    if (pos == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* temp = head;
    int cnt = 1;

    // Traverse to the node just before the target position
    while (temp != nullptr && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }

    // Check if the position is valid
    if (temp == nullptr || temp->next == nullptr) {
        cout << "Position is out of bounds." << endl;
        return head;
    }

    // Delete the target node
    Node* to_delete = temp->next;
    temp->next = to_delete->next;
    delete to_delete;

    return head;
}



int main(){
    Node* head = nullptr;
    int data;
    cout << "Enter input for inserting at beginning ";
    cin >> data;
    insert_at_beginning(head,data);
    print(head);
    cout << "Insert at end ";
    cin >> data;
    vector<int>arr = {11,12,13,14,15};
    cout << "arr to be inserting" << endl;
    for(int i = 0; i < arr.size(); i++){
        insert_at_end(head,arr[i]);
    }
    cout << "after inseting " << endl;
    print(head);

    cout << "Insert at any postion , enter postion where you want to insert: ";
    int pos;
    cin >> pos >> data;
    insert_at_any_pos(head,data,pos);
    cout << "after inseting " << endl;
    print(head);

    delete_at_end(head);
    cout << "after deleting at end " << endl;
    print(head);
    cout << "enter any position to delete " << endl;
    cin >> pos;
    head = delete_at_any_position(head,pos);
    cout << "after deleting at position " << endl;
    print(head);
}
