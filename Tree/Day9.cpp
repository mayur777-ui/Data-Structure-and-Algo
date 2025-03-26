#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

TreeNode* converttotree(vector<int> arr, int i){
    if(i >= arr.size()){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left =converttotree(arr, 2*i+ 1);
    root->right = converttotree(arr,2*i+2);
    return root;
}



// Is given Tree is valid binary tree or not

bool isVal(TreeNode*root,long minV,long maxV){
    if(!root){
        return true;
    }
    if(root->val <= minV || root->val >= maxV) return false;

    return (root->left,minV,root->val) && (root->right,root->val,maxV);
}

bool isValidBst(TreeNode* root){
    return isVal(root,LONG_MIN,LONG_MIN);
}



// two sum in bst
bool find(TreeNode* root,int k, unordered_set<int> &set){
    if(!root){
        return false;
    }
    if(set.count(k - root->val)) return true;
    set.insert(root->val);
    return find(root->left, k,set) || find(root->right, k ,set);
}
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> set;
    return find(root,k,set);
}

int main(){
    vector<int>arr = {5,1,4,3,6}
    TreeNode* root = converttotree(arr,0);
    cout << isValidBst(root);
}