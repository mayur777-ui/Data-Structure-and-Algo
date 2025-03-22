#include<bits/stdc++.h>
using namespace std;

//Diameter of Binary Tree
class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;

    TreeNode(int val){
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};


TreeNode* converttotree(vector<int> arr,int i){
    if(i >= arr.size()){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = converttotree(arr,2*i+ 1);
    root->right = converttotree(arr,2*i+2);
    return root;
}


int FindD(TreeNode* root, int &diameter){
    if(root == nullptr){
        return 0;
    }
    int lh = FindD(root->left, diameter);
    int rh = FindD(root->right,diameter);
    diameter = max(diameter,lh+rh);

    return max(lh,rh) + 1;
}


int Diameter(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    int diameter = 0;
    FindD(root,diameter);
    return diameter;
}



int findwidth(TreeNode* root){
    if(root == nullptr){
        return 0;
    }
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    int maxWidth = 0;
    while(!q.empty()){
        int size = q.size();
        int firstIdx = q.front().second;
        int lastIdx = q.back().second;
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front().first;
            int idx = q.front().second;
            q.pop();

            lastIdx = idx;

            if(node->left) {
                int index =  2*(idx - firstIdx)+1;
                q.push({node->left,index});
            }
            if(node->right){
                int index =  2*(idx - firstIdx) + 2;
                q.push({node->right,index});
            }
        }
        maxWidth = max(maxWidth,(lastIdx - firstIdx) + 1);
    }
    return maxWidth;
}




int main(){
    vector<int>arr = {1,2,3,4,5,6,7};
    int i = 0;
    TreeNode* root = converttotree(arr,i);
    int D = Diameter(root);
    cout << Diameter << " ";

    int width = findwidth(root);
    cout << "\n" << width;
}