#include<bits/stdc++.h>
using namespace std;
// count Subset sum equal to target (DP- 14)(arr element greater then zero)



// int subRecur(int idx , int k, vector<int>&arr,vector<vector<int>>&dp){
//     if(idx == 0){
//         if(k == 0 && arr[idx] == 0) return 2;
//         if(k == 0 || arr[0] == k) return 1;
//         return  0;
//     }

//     if(dp[idx][k] != -1){
//         return dp[idx][k];
//     }
//     // Exclude
//     int notTaken = subRecur(idx - 1, k, arr,dp);

//     int taken = 0;
//     if(arr[idx] <= k){
//         taken = subRecur(idx - 1,k - arr[idx], arr, dp);
//     }

//     return dp[idx][k] = notTaken + taken;
// }

// int subsetSumTok(int n, int k, vector<int>&arr){
//    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return subRecur(n - 1, k, arr,dp);
// }


// int main() {
//     vector<int> arr = {0,0,1};
//     int k = 1;
//     int n = arr.size();

//     // if (subsetSumTok(n, k, arr))
//     //     cout << "Subset with the given target found";
//     // else
//     //     cout << "Subset with the given target not found";
//     cout << subsetSumTok(n, k , arr);
//     return 0;
// }



//find Subarr with sum k;
class Solution{
    public:
    bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if(target == 0)return true;
        if(ind == 0) return arr[ind] == target;
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = subsetSumUtil(ind - 1, target, arr, dp);
        bool take = false;
        if(arr[ind] <= target){
            take = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
        }

        return dp[ind][target] = notTake || take;
    }
     bool subsetSumToK(int n, int k, vector<int>& arr) {
        vector<vector<int>>dp(n, vector<int>(k + 1, -1));
        return subsetSumUtil(n - 1, k, arr, dp);
    }   
};




int main() {
    vector<int> arr = {1, 2, 3, 4};
    int k = 4;
    int n = arr.size();

    Solution sol;
    if (sol.subsetSumToK(n, k, arr))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";

    return 0;
}





// Count Partitions with Given Difference (DP - 18)


int DpCountPartitions(int idx, int k, vector<int>&arr, vector<vector<int>>&dp){
    if(idx == 0){
        if(k == 0 && arr[idx] == 0)return 2;
        if(k == 0 || k == arr[idx]) return 1;
        return 0;
    }

    if(dp[idx][k] != -1){
        return dp[idx][k];
    }

    int nottaken = DpCountPartitions(idx - 1, k, arr, dp);
    int taken = 0;
    if(arr[idx] <= k){
        taken = DpCountPartitions(idx - 1, k - arr[idx], arr, dp);
    }

    return dp[idx][k] = nottaken  + taken;
}


int countPartitions(int d, vector<int>arr){
    int totSum = 0;
    for(int i = 0; i < arr.size(); i++){
        totSum += arr[i];
    }

    if(totSum < d) return 0;
    if((totSum - d)%2 == 1) return 0;
    int s2 = (totSum - d)/2;
    vector<vector<int>>dp(arr.size(), vector<int>(s2 + 1, -1));
    return DpCountPartitions(arr.size() - 1, s2, arr, dp);
}

int main() {

  vector<int> arr = {5,2,6,4};
  int d=3;
                                 
  cout<<"The number of subsets found are " <<countPartitions(d,arr);
}