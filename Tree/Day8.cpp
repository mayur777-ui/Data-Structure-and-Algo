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


// vertical orderTraversal

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



// Top view
// Approach 1.
vector<int> topView(TreeNode *root){
    // code here
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    vector<vector<int>>ans1;
    queue<pair<TreeNode*,int>> q;
    map<int,vector<int>> mp;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* nnode = q.front().first;
            int col = q.front().second;
            q.pop();
            mp[col].push_back(nnode->val);
            if(nnode->left){
                int coltopush = col - 1;
                q.push({nnode->left,coltopush});
            }
            if(nnode->right){
                int coltopush = col + 1;
                q.push({nnode->right,coltopush});
            }
        }
    }
    for(auto it:mp){
        ans1.push_back(it.second);
    }
    
    for(auto it: ans1){
        ans.push_back(it[0]);
    }
    return ans;
}


// Approach 2

vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    queue<pair<TreeNode*,int>> q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front().first;
            int col = q.front().second;
            q.pop();
                mp[col] = node->val;
            if(node->left){
                q.push({node->left,col-1});
            }
            if(node->right){
                q.push({node->right,col+1});
            }
        }
    }

    for(auto it: mp){
        ans.push_back(it.second);
    }
    return ans;
}



// Bottom view

vector <int> bottomView(TreeNode *root){
    // Your Code Here
    vector<int> ans;
if(root == nullptr){
    return ans;
}
queue<pair<TreeNode*,int>> q;
map<int,int>mp;
q.push({root,0});
while(!q.empty()){
    int n = q.size();
    for(int i = 0; i < n; i++){
        TreeNode* node = q.front().first;
        int col = q.front().second;
        q.pop();
        mp[col] = node->val;
        if(node->left){
            q.push({node->left,col-1});
        }
        if(node->right){
            q.push({node->right,col+1});
        }
    }
}

for(auto it: mp){
    ans.push_back(it.second);
}
return ans;
}


void tofind(TreeNode* root,vector<int>&ans,int level,int &maxlevel){
    if(root == nullptr){
        return;
    }
    if(level>maxlevel){
        ans.push_back(root->val);
        maxlevel = level;
    }

    tofind(root->left, ans,level + 1,maxlevel);
    tofind(root->right,ans,level + 1,maxlevel);
    
}

vector<int> leftView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    int maxlevel = -1;
    tofind(root,ans,0,maxlevel);
    return ans;
}


vector<int> leftView(TreeNode* root){
    vector<int>ans;
    if(!root){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        vector<int> temp;
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(temp[0]);
    }

    return ans;
}


void tofindR(TreeNode* root,vector<int>&ans,int level,int&maxlevel){
    if(root == nullptr){
        return;
    }
    if(level > maxlevel){
        ans.push_back(root->val);
        maxlevel = level;
    }

    tofindR(root->right,ans,level+1,maxlevel);
    tofindR(root->left,ans,level+1,maxlevel);
}

vector<int> RightView(TreeNode* root){
    vector<int> ans;
    if(root == nullptr){
        return ans;
    }
    int maxlevel = -1;
    tofindR(root,ans,0,maxlevel);
    return ans;
}


vector<int> RightView(TreeNode* root){
    vector<int>ans;
    if(!root){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int temp;
        for(int i = 0; i < n; i++){
            TreeNode* node = q.front();
            q.pop();
            temp = node->val;
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}


bool isSymmetricUnit(TreeNode* root1,TreeNode* root2){
    if(root1 == nullptr || root2 == nullptr){
        return root1 == root2;
    }

    return (root1->val == root2 -> val) && isSymmetricUnit(root1->left,root2->right) && isSymmetricUnit(root1->right,root2->left);
}
bool isSymmetric(TreeNode* root) {
    if(!root){
        return true;
    }
    if(!root->left && !root->right){
        return true;
    }
    return isSymmetricUnit(root->left,root->right);
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

    vector<int> Topview = topView(root);
    vector<int> BottomView = bottomView(root);
    for(int i = 0; i < Topview.size();i++){
        cout << Topview[i] << " ";
    }
    for(int i = 0; i < BottomView.size();i++){
        cout << BottomView[i] << " ";
    }

    vector<int> leftview = leftView(root);
    for(int i = 0; i < leftview.size();i++){
        cout << leftview[i] << " ";
    }
    vector<int> rightview = RightView(root);
    for(int i = 0; i < rightview.size();i++){
        cout << rightview[i] << " ";
    }

    if(isSymmetric(root)){
        cout<< "True";
    }else{
        cout << "fasle";
    }
}