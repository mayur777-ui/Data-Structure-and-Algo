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



<<<<<<< HEAD
=======
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


>>>>>>> 501e1d4bb74d80c7c1e3631edf16143077509890


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
    return 0;
}