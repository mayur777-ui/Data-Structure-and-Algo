#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};



TreeNode* sortedArrayToBST(vector<int>& arr, int start, int end) {
     if (start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}


bool searchelemt(TreeNode* root, int key) {
    if (root == nullptr) {
        return false; 
    }

    if (root->val == key) {
        return true; // Key found
    } else if (root->val < key) {
        return searchelemt(root->right, key); 
    } else {
        return searchelemt(root->left, key); 
    }
}

TreeNode* insertioninbst(TreeNode* root,int key){
    if(root == nullptr){
        return new TreeNode(key);
    }
    if(root->val == key){
        cout << "Node should be uniqe!";
        return root;
    }

    if(root->val < key){
        root->right = insertioninbst(root->right,key);
    }else{
        root->left = insertioninbst(root->left, key);
    }

    return root;

}


void inOrderTraversal(TreeNode* root) {
    if(root == nullptr){
        return;
    }
    inOrderTraversal(root->left);
    cout << root->val << " ";
    inOrderTraversal(root->right);
}

// Deletion in BST
TreeNode* inordersuc(TreeNode* root){
    TreeNode* curr =root;
    while(curr && curr->left != nullptr){
        curr = curr->left;
    }
    return curr;
}


TreeNode* DeletionInBst(TreeNode* root,int key){
    if(root == nullptr){
        return root;
    }
    if(root->val < key){
        root->right = DeletionInBst(root->right,key);

    }else if(root->val > key){
        root->left = DeletionInBst(root->left,key);
    }else{
        if(root->left == nullptr){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }else if(root->right == nullptr){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode*temp = inordersuc(root->right);
        root->val = temp->val;
        root->right = DeletionInBst(root->right,temp->val);
    }
    return root;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6}; 

    TreeNode* root = sortedArrayToBST(arr, 0, arr.size() - 1);

    cout << "In-order traversal of the constructed BST: ";
    inOrderTraversal(root);
    cout << endl;

    int key = 6;
    if(searchelemt(root, key)){
        cout << "Element " << key <<" found in the BST" << endl;
    }else{
        cout << "key not found!";
    }
    int val;
    cout <<"enter the val for inserting: ";
    cin >> val;
    root = insertioninbst(root,val);
    inOrderTraversal(root);
    cout<< "\nDeleting given key: \n";
    DeletionInBst(root,3);
    inOrderTraversal(root);
    return 0;
}
