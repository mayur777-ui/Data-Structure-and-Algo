// Trapping Rainwater
#include<bits/stdc++.h>
using namespace std;

// broute force

int trap(vector<int> arr){
    int n = arr.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        int j  = i;
        int leftmax = 0;
        int rightmax = 0;
        while(j >= 0){
            leftmax = max(leftmax,arr[j]);
            j--;
        }
        j = i;
        while(j < n){
            rightmax = max(rightmax, arr[j]);
            j++;
        }
        ans += min(leftmax,rightmax) - arr[i];
    }
    return ans;
}




// better solution
int trap(vector<int> arr){
    int n = arr.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    prefix[0] = arr[0];
    suffix[n - 1] = arr[n - 1];
    for(int  i = 1; i < n; i++){
        prefix[i] = max(prefix[i - 1],arr[i]);
    }
    for(int i = n - 2; i >= 0 ;i--){
        suffix[i] = max(suffix[i + 1], arr[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += min(prefix[i],suffix[i]) - arr[i];
    }
    return ans;
}


int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
