#include <bits/stdc++.h>
using namespace std;

// Target Sum (DP - 21) Change II
// Approach 1 (Memoization)
int helper(vector<int> &nums, vector<vector<int>> &dp, int ind, int s)
{
    if (ind == 0)
    {
        if (s == 0 && nums[ind] == 0)
            return 2;
        if (s == 0 || nums[ind] == s)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][s] != -1)
        return dp[ind][s];
    int notTake = helper(nums, dp, ind - 1, s);
    int take = 0;
    if (nums[ind] <= s)
    {
        take = helper(nums, dp, ind - 1, s - nums[ind]);
    }
    return dp[ind][s] = take + notTake;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += nums[i];
    }
    if ((tot - target) % 2 != 0 || tot <= abs(target))
    {
        return 0;
    }
    int s = (tot - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s + 1, -1));
    return helper(nums, dp, n - 1, s);
}

// Approach 2 (Tabulization)
int findTargetSumWayTab(vector<int> &nums, int target)
{
    int n = nums.size();
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += nums[i];
    }
    if ((tot - target) % 2 != 0 || tot < abs(target))
    {
        return 0;
    }
    int s = (tot - target) / 2;
    vector<vector<int>> dp(n, vector<int>(s + 1, 0));
    if (nums[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {
        dp[0][0] = 1;
    }
    if (nums[0] != 0 && nums[0] <= s)
    {
        dp[0][nums[0]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (nums[i] <= j)
            {
                take = dp[i - 1][j - nums[i]];
            }
            dp[i][j] = notTake + take;
        }
    }
    return dp[n - 1][s];
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target);
    cout << findTargetSumWaysTab(nums, target);
}

// 	Coin Change 2 (DP - 22)
// 1.Approach(1) Memoizatoin
int numberOf(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (amount % coins[ind] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int notTake = numberOf(ind - 1, amount, coins, dp);
    int take = 0;
    if (coins[ind] <= amount)
    {
        take = numberOf(ind, amount - coins[ind], coins, dp);
    }
    return dp[ind][amount] = notTake + take;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    if (amount == 0)
    {
        return 1;
    }
    return numberOf(n - 1, amount, coins, dp);
}

int changeTab(int amount, vector<int> &coins){
    int n = coins.size();
    vector<vector<int>>dp(n, vector<int>(amount + 1, 0));
    for(int i = 0; i <= amount; i++){
         if(i % coins[0] == 0){
        dp[0][i] = 1;
    }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= amount; j++){
            int notTake = dp[i - 1][j];
            int take = 0;
            if(j >= coins[i]){
                take = dp[i][j - coins[i]];
            }
            dp[i][j] = notTake + take;
        }
    }
    return dp[n - 1][amount];
}


int main(){
    vector<int>coins ={1,2,5};
    int amount = 5;
    cout << change(amount, coins);
    cout << changeTab(amount , coins);
}




// Unbounded Knapsack (DP - 23)
// Approach 1(Memoization);
int helper(int ind, int W, vector<int>& val, vector<int>& wt, vector<vector<int>>&dp){
    if(ind == 0){
        return W/wt[ind] * val[ind];
    }
    if(dp[ind][W] != -1)return dp[ind][W];
    int notTake = helper(ind - 1, W,val, wt, dp);
    int take =INT_MIN;
    if(W >= wt[ind]){
        take = val[ind] + helper(ind, W-wt[ind], val, wt, dp);
    }
     return dp[ind][W] = max(notTake, take);
}
int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {
    vector<vector<int>>dp(n, vector<int>(W + 1, -1));
    return helper(n - 1,W,val,wt, dp);
}


// Approach 2. (Tabulation)
int unboundedKnapsackTab(int n, int W, vector<int>& val, vector<int>& wt){
    vector<vector<int>>dp(n, vector<int>(W + 1, -1));
    for(int i = 0; i <= W; i++){
        dp[0][i] = (i/wt[0]) * val[0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= W; j++){
            int notTake = dp[i - 1][j];
            int take = INT_MIN;
            if(wt[i] <= j){
                take = val[i] + dp[i][j - wt[i]];
            }

            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][W];
}

int main() {
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int W = 10;
    int n = wt.size();
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsack(n, W, val, wt) << endl;
    cout << "The Maximum value of items the thief can steal is " << unboundedKnapsackTab(n, W, val, wt) << endl;
    return 0;
}


int helper(vector<int>&price, int ind, int n, vector<vector<int>>&dp){
    if(ind == 0){
        return n * price[ind];
    }
    if(dp[ind][n] != -1)return dp[ind][n];
    int notTaKe = helper(price, ind - 1, n, dp);
    int take = INT_MIN;
    int rodLane = ind + 1;  //as we know arr is 0 based index but road lenght is 1 based
    if(rodLane <= n){
        take = price[ind] + helper(price,ind, n - rodLane, dp);
    }
    return dp[ind][n] = max(take, notTake);
}
int rodCutting(vector<int>& price, int n) {
    vector<vector<int>>dp(n, vector<int>(n  + 1, -1));
    return helper(price, n - 1, n,dp);
}

int rodCuttingTab(vector<int>&price, int n){
    vector<vector<int>>dp(n , vector<int>(n + 1, -1));
    for(int i = 0; i <= n; i++){
        dp[0][i] = i * price[0];
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= n; j++){
            int notTake = dp[i - 1][j];
            int take =INT_MIN;
            int roadLane = i + 1;
            if(roadLane <= j){
                take = price[i] + dp[i][j - roadLane];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][n];
}


int main() {
    int n = 8;

    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};

    int maxValue = rodCutting(price, n);
    cout << "The maximum obtainable value is: " << maxValue << endl;

    return 0;
}