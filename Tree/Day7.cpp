#include<bits/stdc.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function for Zig-Zag Level Order Traversal
vector<vector<int>> Zig_Zag_Traversal(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true; // Flag to track direction

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;
        
        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Reverse level if needed
        if (!leftToRight) {
            reverse(level.begin(), level.end());
        }

        ans.push_back(level);
        leftToRight = !leftToRight; // Toggle direction
    }

    return ans;
}

// Function to collect all leaf nodes
void getLeafNodes(TreeNode* root, vector<int>& leaves) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        leaves.push_back(root->val);
        return;
    }

    getLeafNodes(root->left, leaves);
    getLeafNodes(root->right, leaves);
}

// Function to get leaf node traversal
vector<int> leafNodeTraversal(TreeNode* root) {
    vector<int> leaves;
    getLeafNodes(root, leaves);
    return leaves;
}

// Function to build a Binary Tree from an array (Level-order insertion)
TreeNode* convertToTree(const vector<int>& arr, int& index) {
    if (index >= arr.size() || arr[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[index]);
    index++;
    root->left = convertToTree(arr, index);
    root->right = convertToTree(arr, index);
    return root;
}

// Main function
int main() {
    vector<int> arr = {1, 2, 12, 34, 13, 21, 32, 23};
    int i = 0;
    TreeNode* root = convertToTree(arr, i);

    // Zig-Zag Traversal Output
    vector<vector<int>> ans = Zig_Zag_Traversal(root);
    cout << "Zig-Zag Traversal:\n";
    for (auto& level : ans) {
        for (int num : level) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Leaf Node Traversal Output
    vector<int> leafNodes = leafNodeTraversal(root);
    cout << "Leaf Node Traversal: ";
    for (int num : leafNodes) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}





vector<int> printBoundary(TreeNode* root){
    vector<int> arr;
    if(root == nullptr){
        return arr;
    }
}


int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    // Get the boundary traversal
    vector<int> result = printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}


