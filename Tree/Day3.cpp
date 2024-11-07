#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int n):val(n),left(nullptr),right(nullptr){};
};

Node* converttotree(vector<int>arr,int i){
    if (i >= arr.size()) return nullptr;
    Node* root = new Node(arr[i]);
    root->left = converttotree(arr,2*i+1);
    root->right = converttotree(arr,2*i+2);

    return root;
}


// Level traversal 2.
void traversal(Node* root){
    if(root == nullptr) return;
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node* node = q.front();
        q.pop();
        cout << node->val << " ";
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
    }
    
}



int main() {
    vector<int> arr = {1, 2, 12, 34, 13, 21, 32, 23};
    Node* root = converttotree(arr, 0); 
    traversal(root);
    return 0;
}