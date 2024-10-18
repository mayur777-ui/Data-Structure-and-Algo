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





// min sum of subarray


// broute forec
int main() {
    vector<int> arr = {1, 3, 0, 5, 2};
    int n = arr.size();
        int total = 0;
        const int MOD = 1e9 + 7; 
        for(int i = 0; i < n; i++) {
            int cmin = arr[i];
            for(int j = i; j < n; j++) {
                cmin = min(cmin, arr[j]);
                total = (total + cmin) % MOD;
            }
        }
    cout << total;

    return 0;
}


// optimal approach
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long total = 0;
        int mod = 1e9 + 7;
        
        for (int i = 0; i < n; ++i) {
            total = (total + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
        }

        return (int)total;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3, 1, 2, 4};

    int ans = s.sumSubarrayMins(arr);
    cout << ans;
}




// Asteroid collisions 

int main() {
    vector<int> as {-10, 2, -8};  
    stack<int> st;
    
    for (int i = 0; i < as.size(); ++i) {
        bool isPushed = false;
        while (!st.empty() && st.top() > 0 && as[i] < 0){
            if (abs(st.top()) < abs(as[i])) {
                st.pop();
            } else if (abs(st.top()) == abs(as[i])) {
                st.pop();
                isPushed = true;
                break;
            } else {
                isPushed = true;
                break;
            }
        }
        if (!isPushed) {
            st.push(as[i]);
        }
    }

    stack<int> resultStack;
    while (!st.empty()) {
        resultStack.push(st.top());
        st.pop();
    }
    
    while (!resultStack.empty()) {
        cout << resultStack.top() << " ";
        resultStack.pop();
    }
    cout << endl;

    return 0;
}

// sum of subarray ranges
// Broute force
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            int minval = nums[i];
            int maxval = nums[i];
            for(int j = i; j < n; j++){
                minval = min(minval,nums[j]);
                maxval = max(maxval,nums[j]);
                sum += (long long)(maxval-minval);
          }
        }
        return sum;
    }
};


int main(){
    Solution s;
    vector<int> n {1,2,3};
    long long sum = subArrayRanges(n);
    cout << sum;
}


// Optimal approach