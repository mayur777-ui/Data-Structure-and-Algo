#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int n) : val(n), left(nullptr), right(nullptr) {}
};

Node* converttotree(vector<int> arr, int i) {
    if (i >= arr.size()) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = converttotree(arr, 2 * i + 1);
    root->right = converttotree(arr, 2 * i + 2);
    return root;
}

// Level traversal
void traversal(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
    cout << endl;
}

// // Height of binary tree- Approach 1. (method level order traversal) 
int HeightofTree(Node* root) {
    if (root == nullptr) return 0;
    queue<Node*> q;
    q.push(root);
    int height = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();
            if (front->left != nullptr) q.push(front->left);
            if (front->right != nullptr) q.push(front->right);
        }
        height++;
    }
    return height;
}


// Approach-2.
int HeightofTree(Node* root) {
    if(root == nullptr){
        return 0;
    }

    int lh = HeightofTree(root->left);
    int rh = HeightofTree(root->right);

    return 1+ max(lh,rh);
}





// Check if the Binary tree is height-balanced or not
// Approach 1.
bool checkBalance(Node* root){
    if(root == nullptr){
        return true;
    }

    int lh = HeightofTree(root->left);
    int rh = HeightofTree(root->right);

    if(abs(lh - rh) <= 1 && checkBalance(root->left) && checkBalance(root->right)){
        return true;
    }
    return false;
}

// //Approach 2.


int check(Node* root){
    if(root == nullptr){
        return 0;
    }
    int lh = check(root->left);
    if(lh == -1){
        return -1;
    }
    int rh = check(root->right);
    if(rh == -1){
        return -1;
    }

    if(abs(lh - rh) > 1){
        return -1;
    }

    return max(lh,rh)+ 1;
}
bool checkBalance(Node* root){
    if(root == nullptr){
        return true;
    }
    return check(root) != -1;
}


int main() {
    vector<int> arr = {1, 2, 12, 34, 13, 21, 32, 23};
    Node* root = converttotree(arr, 0); 
    traversal(root);
    int height = HeightofTree(root);
    cout << "Height of the tree: " << height << endl;
    bool isBalance = checkBalance(root);
    cout << (isBalance ? "True" : "false");
    return 0;
}
