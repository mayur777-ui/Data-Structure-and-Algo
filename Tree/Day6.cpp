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

TreeNode* convertotree(vector<int> arr, int i){
    if(i >= arr.size()){
        return nullptr;
    }
    TreeNode* root = new TreeNode(arr[i]);
    root->left = convertotree(arr,2*i+1);
    root->right = convertotree(arr,2*i+2);

    return root;
}



// Approach 1.(iteretive approach)
void Path_of_root_to_each_leaf(TreeNode* root){
    if(root == nullptr){
        cout << "not any leaf found";
        return;
    }
    stack<pair<TreeNode*,vector<int>>> st;
    st.push({root,{root->val}});
    while(!st.empty()){
        TreeNode* node = st.top().first;
        vector<int> path = st.top().second;
        st.pop();
        if(!node->left && !node->right){
            for(int i = 0; i < path.size(); i++){
                cout << path[i] << " ";
            }
            cout << endl;
        }

        if(node->right){
            vector<int> newPath = path;
            newPath.push_back(node->right->val);
            st.push({node->right,newPath});
        }

        if(node->left){
            vector<int> newPath = path;
            newPath.push_back(node->left->val);
            st.push({node->left,move(newPath)});
        }
    }

}




// Approach 2.(recursive approach)
void Path_of_root_to_each_leaf(TreeNode* root, vector<int>&path){
    if(root == nullptr){
        return;
    }

    path.push_back(root->val);
    
    if(!root->left && !root->right){
        for(int i = 0; i < path.size(); i++){
            cout << path[i]  << " ";
        }
        cout << endl;
    }

    Path_of_root_to_each_leaf(root->left, path);
    Path_of_root_to_each_leaf(root->right,path);

    path.pop_back();
}


int dfs(TreeNode* root,int&maxSum){
    if(!root){
        return 0;
    }

    int lmax = max(dfs(root->left,maxSum),0);
    int rmax = max(dfs(root->right,maxSum),0);

    int currSum = root->val + lmax + rmax;
    maxSum = max(maxSum,currSum);
    return root->val + max(lmax,rmax);
}

int maximumPathSum(TreeNode* root){
    int maxSum = INT_MIN;
    dfs(root,maxSum);
    return maxSum;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int i = 0;
    TreeNode* root = convertotree(arr,0);
    // Path_of_root_to_each_leaf(root);
    vector<int> path;
    // Path_of_root_to_each_leaf(root,path);
    int maxPathSum = maximumPathSum(root);
    cout << maxPathSum;
}


// Approach 1(USING SEACRCH FUNCTION)

int Search(vector<int> inorder,int val,int left,int right){
    for(int i = left; i <= right; i++){
       if(val == inorder[i]){
            return i;
       }
    }
    return -1;
}


TreeNode* helperBuildTree(vector<int> inorder,vector<int> preorder, int&preIdx,int left,int right){
    if(left > right){
        return nullptr;
    }

    int rootVal = preorder[preIdx];
    TreeNode* root = new TreeNode(rootVal);
    preIdx++;

    int index = Search(inorder,rootVal,left,right);

    root->left = helperBuildTree(inorder,preorder,preIdx,left,index-1);
    root->right=helperBuildTree(inorder,preorder,preIdx,index+1,right);

    return root;
}







void printLevelOrder(TreeNode *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<TreeNode *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        TreeNode *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->val) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}



int main() {
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    TreeNode* root = buildTree(inorder, preorder);

    printLevelOrder(root);

    return 0;
}