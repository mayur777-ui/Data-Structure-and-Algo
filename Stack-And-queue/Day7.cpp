#include<iostream>
#include<string>
using namespace std;



// "Customer Queue Management System with Latecomer Removal"
struct Node {
    string name;
    int restime;
    int arrivetime;
    Node* next;

    public:
    Node(string n, int res, int arr) {
        name = n;
        restime = res;
        arrivetime = arr;
        next = nullptr;
    }
};

class Queue {
    Node* st;  // start of the queue
    Node* end; // end of the queue
    int size;

    public:
    Queue() {
        st = nullptr;
        end = nullptr;
        size = 0;
    }

    void enqueue(string n,int arr,int res) {
        Node* nptr = new Node(n, res, arr);
        if (end == nullptr) {
            st = nptr;
            end = nptr;
        } else {
            end->next = nptr;
            end = nptr;
        }
        size++;
    }

    void dequeue() {
        if (st == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = st;
        st = st->next;
        cout << "Arrival time: " << temp->arrivetime << endl;
        cout << "Registration time: " << temp->restime << endl;
        size--;
        delete temp;
        if (st == nullptr) end = nullptr; // If queue becomes empty, reset end
    }

    int Size() {
        return size;
    }

    void removellatecommer() {
        if (st == nullptr) {
            cout << "No customer is available" << endl;
            return;
        }

        Node* temp = st;
        Node* pre = nullptr;

        while (temp != nullptr) {
            if (temp->arrivetime > temp->restime) {
                if (temp == st) {
                    Node* toDelete = st;
                    st = st->next;
                    delete toDelete;
                    temp = st;
                    if (st == nullptr) end = nullptr; 
                } else {
                    pre->next = temp->next;
                    if (temp == end) { 
                        end = pre;
                    }
                    delete temp;
                    temp = pre->next; 
                }
                size--;
            } else {
                pre = temp;
                temp = temp->next;
            }
        }
    }

    void print() {
        if (st == nullptr) {
            cout << "No entries to print!" << endl;
            return;
        }

        Node* temp = st;
        int i = 1;
        while (temp != nullptr) {
            cout << "Customer " << i << ": " << temp->name << " | Arrival time: " << temp->arrivetime
                 << " | Registration time: " << temp->restime << endl;
            temp = temp->next;
            i++;
        }
    }
};

int main() {
    int n;
    cout << "Enter number of customers: ";
    cin >> n;
    cin.ignore(); // Ignore newline after number input

    if (n == 0) {
        cout << "No customers to process!" << endl;
        return 0;
    }

    Queue q;
    int arr, res;
    string name;

    for (int i = 0; i < n; i++) {
        cout << "Enter customer " << i + 1 << " details" << endl;
        cout << "Customer name: ";
        getline(cin, name);
        cout << "Arrival time: ";
        cin >> arr;
        cout << "Registration time: ";
        cin >> res;
        cin.ignore(); 
        q.enqueue(name, arr, res);
    }

    cout << endl << "Removing latecomers..." << endl;
    q.removellatecommer();
    cout << endl << "Remaining customers in the queue:" << endl;
    q.print();

    return 0;
}
