#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):data(val),left(nullptr),right(nullptr){};
};






// convert to tree
TreeNode* convertotree(vector<int>&arr,int i){
    if(i >= arr.size()) return nullptr;
    TreeNode* root = new TreeNode(arr[i]);
    root->left = convertotree(arr,2*i+1);
    root->right = convertotree(arr,2*i+2);
}

// DFS TRAVERSAL
// 1.preorder traversal
void preorder(TreeNode* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// 2.inorder traversal
void inorder(TreeNode* root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// 3.postorder traversal
void postorder(TreeNode* root){
    if(root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}


// BFS ->LEVEL ORDER TRAVERSAL
vector<vector<int>> leveltraversal(TreeNode* root){
    vector<vector<int>> res;
    if(root == nullptr) return res;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i = 0; i < size; i++){
            TreeNode* node =q.front();
            q.pop();
            level.push_back(node->data);
            if(node->left){
                q.push(node->left);
            }
            if(node->right != nullptr){
                q.push(node->right);
            }
        }
        res.push_back(level);
    }
    return res;
}


void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int n = arr.size();
    int i = 0;
    TreeNode* root = convertotree(arr,i);
    preorder(root);
    postorder(root);
    inorder(root);

    vector<vector<int>> ans = leveltraversal(root);
    for(const vector<int>& level : ans){
        printVector(level);
    }
}
