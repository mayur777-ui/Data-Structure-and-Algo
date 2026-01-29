#include<bits/stdc++.h>
using namespace std;



// Partition Array Into Two Arrays to Minimize Sum Difference


// Approach 1.(Memoization)
bool ans(vector<vector<int>>& dp,vector<int>& nums, int ind, int k){
    if(k == 0){
        return dp[ind][k] = true;
    }

    if(ind == 0){
        return dp[ind][k] = (nums[ind] == k);
    }

    if(dp[ind][k] != -1){
        return dp[ind][k];
    }
    bool notTake = ans(dp, nums, ind - 1, k);
    bool take = false;
    if(nums[ind] <= k){
        take = ans(dp, nums, ind - 1, k - nums[ind]);
    }
    return dp[ind][k] = notTake || take;
}

int minSubsetSumDifference(vector<int>& arr, int n) {
    int totSum = 0;
    for(int i = 0; i < n; i++){
        totSum += arr[i];
    }
    vector<vector<int>>dp(n, vector<int>(totSum + 1, -1));
    for(int i = 0; i <=totSum; i++){
        bool dumy = ans(dp,arr, n - 1, i);
    }
    int mini = INT_MAX;
    for(int i = 0; i <= totSum/2; i++){
        if(dp[n - 1][i]){
            int diff = abs(totSum - 2 * i);
            mini = min(mini, diff);
        }
    }
    return mini;
}



// #Approach(tabulation) 

int minSubsetSumDifferenceTab(vector<int>& arr, int n){
    int totSum = 0;
    for(int i = 0; i < n; i++){
        totSum += arr[i];
    }
    vector<vector<bool>>dp(n, vector<bool>(totSum + 1, false));
    for (int i = 0; i < n; i++) {
            dp[i][0] = true;
    
    }
    if (arr[0] <= totSum)
            dp[0][arr[0]] = true;

        
    for(int i = 1; i < n; i++){
        for(int k = 0;k <= totSum; k++){
            bool notTaken = dp[i - 1][k];
            bool taken = false;
            if(arr[i] <= k){
                taken = arr[i] + dp[i - 1][k - arr[i]];
            }
            dp[i][k] = taken || notTaken;
        }
    }
    int Mini = INT_MAX;
    for(int i = 0; i <= totSum/2; i++){
        if(dp[n - 1][i]){
            int diff = abs(totSum - 2*i);
            Mini = min(Mini, diff);
        }
    }
    return Mini;
}
int main() {
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);
    cout << "The minimum absolute difference is: " << minSubsetSumDifferenceTab(arr, n);

    return 0;
}

