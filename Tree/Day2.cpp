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
TreeNode* DeletionInBst(TreeNode* root, int key) {
    // Base case: if the tree is empty, return null
    if (root == nullptr) {
        return root;
    }

    // Step 1: Find the node to delete
    if (root->val < key) { // The key is greater than root's value
        root->right = DeletionInBst(root->right, key);
    } else if (root->val > key) { // The key is smaller than root's value
        root->left = DeletionInBst(root->left, key);

    } else { // root->val == key, so we found the node to delete

        // Case 1: Node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root; // Delete the current node
            return temp; // Return the subtree without this node
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Node with two children
        // Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = inordersuc(root->right);
        
        // Copy the inorder successor's value to the current node
        root->val = temp->val;

        // Delete the inorder successor
        root->right = DeletionInBst(root->right, temp->val);
    }
    return root; // Return the (possibly updated) root
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
    cout << "Enter key which is persent in bst and you want to delete: ";
    int n;
    cin >> n;
    DeletionInBst(root,n);
    cout<< "\nDeleting given key: \n";
    inOrderTraversal(root);
    return 0;
}