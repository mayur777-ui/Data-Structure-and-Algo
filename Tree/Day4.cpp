#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};



// floor 
int findFloor(Node* root, int key) {
    int floor = -1;
    while (root) {
        if (root->data == key) {
            return root->data; // Exact match
        }
        if (root->data < key) {
            floor = root->data; // Update floor
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return floor;
}


int findCeil(Node* root, int key) {
    int floor = -1;
    while (root) {
        if (root->data == key) {
            return root->data; // Exact match
        }
        if (root->data > key) {
            floor = root->data; // Update floor
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return floor;
}



Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 10);
    root = insert(root, 14);

    int key = 5;

    cout << "Floor of " << key << " is " << findFloor(root, key) << endl;
    cout << "Ceil of " << key << " is " << findCeil(root, key) << endl;

    return 0;
}
