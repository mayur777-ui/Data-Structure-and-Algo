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