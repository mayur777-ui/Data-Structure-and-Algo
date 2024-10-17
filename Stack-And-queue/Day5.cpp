#include<bits/stdc++.h>
using namespace std;



// Trapping Rainwater
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




// Optimal approah;
int trap(vector<int>& arr) {
    int n = arr.size();
    int left = 0, right = n - 1;
    int maxleft = 0, maxRight = 0;
    int res = 0;
    while(left <= right){
        if(arr[left] <= arr[right]){
            if(arr[left] >= maxleft){
                maxleft = arr[left];
            }else{
                res += maxleft - arr[left];
            }
            left++;
        }else{
            if(arr[right] >= maxRight){
                maxRight = arr[right];
            }else{
                res += maxRight - arr[right];
            }
            right--;
        }
    }
    return res;
}


int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
