// CIRCULAR LINKEDLIST
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};



// INSERTION AT BEGINNING 
Node* insertAtBeginning(Node* last, int value){
    
    Node* newNode = new Node(value);

    
    
    if (last == nullptr) {
        newNode->next = newNode;
        return newNode;
    }

    
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

// INSERTION AT END
Node* insertAt_end(Node* last, int val){
    Node* newNode = new Node(val);
    if(last == nullptr){
        newNode->next = newNode;
        last = newNode;
        return last;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;
    return last;
}

// INSERTION AT ANY POSITION
Node* insertAt_any_pos(Node* last,int val,int pos){
    if(last == nullptr){
        if(pos != 1){
            return last;
        }
        Node* nptr = new Node(val);
        nptr->next = nptr;
        last = nptr;
        return last;
    }

    if(pos == 1){
        Node* nptr = new Node(val);
        nptr->next = last->next;
        last->next = nptr;
        return last;
    }

    Node* head = last->next;
    int cnt = 0;
    Node* nptr = new Node(val);
    while(true){
        cnt++;
        if(cnt == pos - 1){
            break;
        }
        head = head->next;
        if(head == last->next){
            cout << "position is out of bound!" << endl;
            return last;
        }
    }
    nptr->next = head->next;
    head->next = nptr;
    if(head == last){
        last = nptr;
    }
    return last;
    
}



Node* delete_at_beginning(Node* last){
    if(last == nullptr){
        return last;
    }

    Node* head = last->next;
    if(head == last){
        delete last;
        last = nullptr;
        return last;
    }else{
        last->next = head->next;
        delete head;
        return last;
    }
}



Node* delete_at_end(Node* last){
    if(last == nullptr){
        return last;
    }
    
    Node* head = last->next;
    if(head == last){
        delete last;
        last ==  nullptr;
        return last;
    }else{
        Node* temp = head;
        while(temp->next != last){
            temp = temp->next;
        }
        temp->next = head;
        delete last;
        last = temp;
        return last;
    }
}

Node* Deleteion_at_any_position(Node* last, int pos) {
    if (last == nullptr) {
        return last;
    }
    Node* head = last->next;
    if (pos == 1) {
        if (head == last) {
            delete last;
            return nullptr;
        }
        last->next = head->next;
        delete head;
        return last;
    }
    Node* curr = head;
    int cnt = 1;
    Node* pre = nullptr;
    while (cnt < pos && curr != last) { 
        pre = curr;
        curr = curr->next;
        cnt++;
    }
    if (cnt != pos) {
        return last;
    }
    pre->next = curr->next;
    if (curr == last) {
        last = pre;
    }
    delete curr;
    return last;
}




void printList(Node* last){
  if(last == NULL) return;
  
    
    Node* head = last->next;
    while (true) {
        cout << head->data << " ";
        head = head->next;
        if (head == last->next)
            break;
    }
    cout << endl;
}




int main(){

    
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;

    cout << "Original list: ";
    printList(last);

    last = insertAtBeginning(last, 5);

    cout << "List after inserting 5 at the beginning: ";
    printList(last);
    last = insertAt_end(last,6);
    cout << "List after inserting end: ";
    printList(last);

    int pos = 6;
    last = insertAt_any_pos(last,10,pos);
    cout << "List after inserting at position " << pos << "\n";
    printList(last);


    last = delete_at_beginning(last);
    cout << "List after deleting at beginning: ";
    printList(last);

    last = delete_at_end(last);
    cout << "List after deleting at end: ";
    printList(last);
    last = Deleteion_at_any_position(last, 7);
    cout << "List after deleting at position 2: ";
    printList(last);
    return 0;
}
