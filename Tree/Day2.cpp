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

    return 0;
}
