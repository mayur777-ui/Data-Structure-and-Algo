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



// #Approach(tabulation)  (leetcode 2035) (not solve with this method we need a method who called for METM Because the dp matrix in that leetcode getting to big and that is not handlable case)

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



// Coin Change(with 2-d approach)
// 1.Approach (Memoization)
int helper(vector<int>&coins, int ind, int amount, vector<vector<int>>&dp){
    if(ind == 0){
        if(amount % coins[ind] == 0){
            return amount/coins[ind];
        }else{
            return 1e9;
        }
    }
    if(dp[ind][amount] != -1)return dp[ind][amount];
    int nottake = helper(coins, ind - 1 , amount, dp);
    int take = 1e9;
    if(coins[ind] <= amount){
        take = 1 + helper(coins, ind, amount - coins[ind], dp);
    }
    return dp[ind][amount] = min(take, nottake);
}

int coinChange(vector<int>& coins, int amount, int n) {
    vector<vector<int>>dp(n,vector<int>(amount + 1, -1));
    int ans = (helper(coins, n - 1, amount, dp) == 1e9)? -1: helper(coins, n - 1, amount, dp);
    return ans;
}

// Approach 2(tabulation)
int coinChangeTab(vector<int>& coins, int amount, int n){
    vector<vector<int>>dp(n,vector<int>(amount + 1, -1));
    for(int i = 0; i <= amount; i++){
        if(i% coins[0] == 0){
            dp[0][i] = i/coins[0];
        }else{
            dp[0][i] = 1e9;
        }
    }
    for(int i = 1; i < n; i++){
        for(int k = 0; k <= amount; k++){
            int NotTake = dp[i - 1][k];
            int take = 1e9;
            if(coins[i] <= k){
                take = 1 + dp[i][k - coins[i]];
            }
            dp[i][k] = min(take, NotTake);
        }
    }

    return dp[n - 1][amount];
}

int main(){
    vector<int>coins = {1,2,5};
    int amount = 11;
    int n = coins.size();
    cout  << coinChange(coins, amount, n);
    cout  << coinChangeTab(coins, amount, n);
}


