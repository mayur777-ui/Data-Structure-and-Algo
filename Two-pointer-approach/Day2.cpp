// 3-SUM  PROBLEM
#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>temp;
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    vector<int>t = {nums[i], nums[l], nums[r]};
                    sort(t.begin(), t.end());
                    temp.push_back(t);
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l - 1])l++;
                    while(r < n && nums[r] == nums[r + 1])r--;
                }else if(sum < 0){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return temp;
}

int main(){
    vector<int>arr = {0,0,0};
    vector<vector<int>>ans = threeSum(arr);


    for(int i = 0; i < ans.size(); i++){
        for(int j = 0;j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}