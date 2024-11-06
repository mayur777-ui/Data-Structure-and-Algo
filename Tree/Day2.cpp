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
        root->right = insertioninbst(root->left,key);
    }else{
        root->left = insertioninbst(root->left, key);
    }

    return root;

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
        root->right = insertioninbst(root->left,key);
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
    int val;
    cout <<"enter the val for inserting: ";
    cin >> val;
    root = insertioninbst(root,val);
    inOrderTraversal(root);
    return 0;
}