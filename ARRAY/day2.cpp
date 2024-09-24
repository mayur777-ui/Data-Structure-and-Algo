// Find the number that appears once, and the other numbers twice


// #include <bits/stdc++.h>
// using namespace std;

// int getSingleElement(vector<int> &arr) {
//     //size of the array:
//     int n = arr.size();

//     // XOR all the elements:
//     int xorr = 0;
//     for (int i = 0; i < n; i++) {
//         xorr = xorr ^ arr[i];
//     }
//     return xorr;
// }

// int main()
// {
//     vector<int> arr = {4, 1, 2, 1, 2};
//     int ans = getSingleElement(arr);
//     cout << "The single element is: " << ans << endl;
//     return 0;
// }



// Longest Subarray with given Sum K(Positives)

// Soulution 1;

// #include <iostream>
// using namespace std;

// int Largesub(int a[],int n, int k){
//     int len = 0;
//     for(int i = 0; i < n; i++){
//         for(int j = i; j < n; j++){
//             int sum = 0;
//             for(int l = i; l<=j;l++){
//                 sum = sum + a[l];
//                 if(sum == k){
//                     len = max(len,j-i+1);
//                 }
//             }
//         }
//     }
//     return len;
// }
// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int k;
//     cin >> n;
//     cout << Largesub(a,n,k);
// }




// Approach.2

// #include <iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int  maxsublen(vector<int>&a,int n,int k){
//     int maxlen = 0;
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i; j < n;j++){
//             sum = sum + a[j];
//             if(sum == k){
//                 maxlen = max(maxlen, j - i + 1);
//             }
//         }
//     }
//     return maxlen;   
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i = 0;i< n;i++){
//         cin >> a[i];
//     }
//     int k;
//     cin >>k;
//     cout << maxsublen(a,n,k);
// }

// // Approach 3
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//     }
//     int k;
//     cin >> k;
//     int l = 0;
//     int r = 0;
//     int sum= a[0];
//     int maxlen = 0;
//     while(r < n){
//         while(sum > k && l <= r){
//             sum -= a[l];
//             l++;
//         }
//         if(sum == k){
//             maxlen = max(maxlen,r - l + 1);
//         }
//         r++;
//         if(r  < n) sum = sum + a[r];
//     }

//     cout << maxlen;
// }



// getmaxsublen

// #include <iostream>
// using namespace std;
// int getmaxsublen(int a[],int n,int k){ 
//     int r = 0;
//     int l = 0;
//     int sum = a[0];
//     int len = 0;
//     while(r < n){
//         while(sum > k && l <= r){
//             sum -= a[l];
//             l++;
//         }
//         if(k == sum){
//             len = max(len, r-l+1);
//         }
//         r++;
//         if(r < n) sum = sum + a[r];
//     }
//     return len;
// }

// int main(){
//     int n;
//     cin >> n;
//     int a[n];
//     for(int i = 0; i< n;i++){
//         cin >> a[i];
//     }
//     int k;
//     cin >> k;
//     cout << getmaxsublen(a,n,k);
// }



// // TWO FIND TWOSUM PROBLEM
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// // Function to check if a pair with the given sum exists
// bool hasPairWithSum(const vector<int>& nums, int target) {
//     unordered_map<int, int> map;  // Hash map to store the elements
    
//     for (int num : nums) {
//         int complement = target - num;  // Complement find karna
        
//         // Check karte hain agar complement already map mein hai
//         if (map.find(complement) != map.end()) {
//             return true;  // Pair mil gaya
//         }
        
//         // Current element ko map mein add karte hain
//         map[num] = 1;
//     }
    
//     return false;  // Pair nahi mila
// }

// int main() {
//     int n, target;
    
//     // Array ka size input lete hain
//     cout << "Enter the number of elements: ";
//     cin >> n;
    
//     vector<int> nums(n);
    
//     // Array ke elements input lete hain
//     cout << "Enter the elements: ";
//     for (int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }
    
//     // Target sum input lete hain
//     cout << "Enter the target sum: ";
//     cin >> target;
    
//     // Check karte hain ki pair exist karta hai ya nahi
//     if (hasPairWithSum(nums, target)) {
//         cout << "A pair with sum " << target << " exists in the array." << endl;
//     } else {
//         cout << "No pair with sum " << target << " exists in the array." << endl;
//     }

//     return 0;
// }




// FINDIN sub arr with maximum sum

// #include <bits/stdc++.h>
// using namespace std;

// long long maxSubarraySum(int arr[], int n) {
//     long long maxi = LONG_MIN; // maximum sum
//     long long sum = 0;

//     int start = 0;
//     int ansStart = -1, ansEnd = -1;
//     for (int i = 0; i < n; i++) {

//         if (sum == 0) start = i; // starting index

//         sum += arr[i];

//         if (sum > maxi) {
//             maxi = sum;

//             ansStart = start;
//             ansEnd = i;
//         }

//         // If sum < 0: discard the sum calculated
//         if (sum < 0) {
//             sum = 0;
//         }
//     }

//     //printing the subarray:
//     cout << "The subarray is: [";
//     for (int i = ansStart; i <= ansEnd; i++) {
//          cout << arr[i];
//          if (i < ansEnd - 1){
//             cout << ",";
//          }
//     }
//     cout << "]\n";

//     // To consider the sum of the empty subarray
//     // uncomment the following check:

//     //if (maxi < 0) maxi = 0;

//     return maxi;
// }