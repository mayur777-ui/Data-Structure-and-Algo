// Trapping Rainwater
#include<bits/stdc++.h>
using namespace std;

// broute force

// int trap(vector<int> arr){
//     int n = arr.size();
//     int ans = 0;
//     for(int i = 0; i < n; i++){
//         int j  = i;
//         int leftmax = 0;
//         int rightmax = 0;
//         while(j >= 0){
//             leftmax = max(leftmax,arr[j]);
//             j--;
//         }
//         j = i;
//         while(j < n){
//             rightmax = max(rightmax, arr[j]);
//             j++;
//         }
//         ans += min(leftmax,rightmax) - arr[i];
//     }
//     return ans;
// }





int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}