#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = left;
        this->right = right;
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




vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    if(root ==  nullptr){
        return ans;
    }

    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root,{0,0}});
    map<int,vector<pair<int,int>>> mp;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            auto [node,it] = q.front();
            int col = it.second;
            int row = it.first;
            q.pop();
            
            mp[col].push_back({row,node->val});
            if(node->left){
                int rowtopush = row + 1;
                int coltopush = col - 1;
                q.push({node->left,{rowtopush,coltopush}});
            }
            if(node->right){
                int rowtopush = row + 1;
                int coltopush = col + 1;
                q.push({node->right,{rowtopush,coltopush}});
            }
        }
    }

    for(auto& it : mp){
          auto& vec = it.second;
          sort(vec.begin(), vec.end());
          vector<int> colValues;
        for(auto& p : vec) {
            colValues.push_back(p.second);
        }
        ans.push_back(colValues);  
    }
    return ans;
}



int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int i = 0;
    TreeNode* root = converttotree(arr, i);
    vector<vector<int>> ans = verticalTraversal(root);
    for(auto it:ans){
        for(auto it1:it){
            cout << it1 << " ";
        }
        cout << endl;
    }
}