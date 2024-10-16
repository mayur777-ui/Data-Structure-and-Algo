#include<bits/stdc++.h>
using namespace std;



//  Next Greater Element (not circular)


// broute force
vector<int> nextGreaterElements(vector<int>& nums1, vector<int>& nums2) {
    vector<int> temp;
    for(int i = 0 ; i < nums1.size(); i++){
        bool found = false;
        for(int j = 0; j < nums2.size();j++){
            if(nums1[i] == nums2[j]){
                for(int k = j + 1; k < nums2.size();k++){
                    if(nums1[i] < nums2[k]){
                        temp.push_back(nums2[k]);
                        found = true;
                        break;
                    }
                }
                if(!found){
                    temp.push_back(-1);
                }
                break;
            }
        }
    }
    return temp;
}
// Optimal for in one given array only(not for circular)
vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }
            st.push(nums[i]);
        }
        return nge;
    }


// Optimal for two array(not for circular)
vector<int> nextGreaterElements(vector<int>& nums1,vector<int>& nums2){
  stack<int>st;
    unordered_map<int, int> nge_map;
    int n2 = nums2.size();
    for(int i = 0; i < n2; i++){
        nge_map[nums2[i]] = -1;
    }
    for(int i = n2 - 1; i >= 0; i--){
        while(!st.empty()&& st.top() <= nums2[i]){
            st.pop();
        }
        if(!st.empty()){
            nge_map[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    vector<int>result;
    for(auto num:nums1){
        result.push_back(nge_map[num]);
    }

    return result;
}

int main() {
  vector < int > v1 {5,6,0};
  vector < int > v {5,7,1,2,6,0};
  // vector < int > res =  nextGreaterElements(v);
  vector < int > res =  nextGreaterElements(v1,v);
  cout << "The next greater elements are" << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
}
