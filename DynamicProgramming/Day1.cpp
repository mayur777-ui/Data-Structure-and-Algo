#include<bits/stdc++.h>
using namespace std;

// frog Jump problem
// My version 1.
int findCost(vector<int>&height, vector<int>&dp,int idx){
        if(idx == 0){
            return 0;
        }
        if(idx == 1){
            return dp[idx] = findCost(height, dp,idx - 1) + abs(height[idx] - height[idx - 1]);
        }
        int left = dp[idx - 1] != -1 ? dp[idx - 1] + abs(height[idx] - height[idx - 1]) : findCost(height, dp,idx - 1) + abs(height[idx] - height[idx - 1]);
        int right = dp[idx - 2] != -1 ? dp[idx - 2] + abs(height[idx] - height[idx - 2]) : findCost(height, dp,idx - 2) + abs(height[idx] - height[idx - 2]);
        return dp[idx] = min(left, right); 
}


// Standered method
int findCost1(vector<int>&height, vector<int>&dp,int idx){
    if(idx == 0){
        return 0;
    }
    if(dp[idx] != -1){
        return dp[idx];
    }

    int left= findCost1(height, dp,idx - 1) + abs(height[idx] - height[idx - 1]);
    int right =INT_MAX;
    if(idx > 1){
        right = findCost1(height, dp,idx - 2) + abs(height[idx] - height[idx - 2]);
    }
    return dp[idx] = min(left,right);
}


int main() {
  vector<int> height{30,10,60 , 10 , 60 , 50};
  int n=height.size();
  vector<int>dp(n+1, -1);
  cout<<findCost(height,dp,n-1) << "\n";
  cout <<findCost1(height,dp,n-1);
}




// Ninja's Training (DP 7)

// Normal Recursion
int ninjaRecursion(int day, int last, vector<vector<int>>&points){
    if(day == 0){
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != last){
                maxi = max(maxi , points[day][i]);
            }
        }

        return maxi;
    }

    int maxi = 0;
    for(int i = 0; i < 3; i++){
        if(i != last){
            int pts = points[day][i] + ninjaRecursion(day - 1, i , points);
            maxi = max(pts, maxi);
        }
    }

    return maxi;
}

int ninjaTrainingWithNormal(int n , vector<vector<int>>&points){
    return ninjaRecursion(n - 1, 3, points);
}

// Memoization Dp

int ninjaMemo(int day, int last, vector<vector<int>>&points, vector<vector<int>>&dp){
    if(day == 0){
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != last){
                maxi = max(maxi , points[day][i]);
            }
        }

        return dp[day][last] = maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for(int i = 0; i < 3; i++){
        if(i != last){
            int pts = points[day][i] + ninjaMemo(day - 1, i , points,dp);
            maxi = max(pts, maxi);
        }
    }

    return dp[day][last] = maxi;
}

int ninjaTrainingwithDpMemo(int n , vector<vector<int>>&points){
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return ninjaMemo(n - 1, 3, points, dp);
}


int main(){
    vector<vector<int>> points = {{10,50,1},{5,100,1},{200,10,1}};
    int  n = points.size();
    int maxMarite = ninjaTrainingWithNormal(n, points);
    int maxMarite1 = ninjaTrainingwithDpMemo(n,points);
    cout << "Normal Recursion: " << maxMarite;
    cout << "Memoization DP :" << maxMarite1;
}




