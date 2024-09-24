
// find next permutation 
// #include <bits/stdc++.h>
// using namespace std;

// vector<int> nextGreaterPermutation(vector<int> &a, int n) {
//     int ind = -1;
    
//     // Step 1: Find the first decreasing element from the end
//     for(int i = n - 2; i >= 0; i--) {
//         if(a[i] < a[i + 1]) {
//             ind = i;
//             break;
//         }
//     }
    
//     // If no such element is found, the array is in descending order
//     if(ind == -1) {
//         reverse(a.begin(), a.end());
//         return a;
//     }
    
//     // Step 2: Find the smallest element larger than a[ind] from the right side
//     for(int i = n - 1; i > ind; i--) {
//         if(a[i] > a[ind]) {
//             swap(a[i], a[ind]);
//             break;  // Only swap once
//         }
//     }
    
//     // Step 3: Reverse the sequence from ind + 1 to the end
//     reverse(a.begin() + ind + 1, a.end());
    
//     return a;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for(int i = 0; i < n; i++) {
//         cin >> A[i];
//     }
    
//     vector<int> ans = nextGreaterPermutation(A, n);

//     cout << "The next permutation is: [";
//     for (auto it : ans) {
//         cout << it << " ";
//     }
//     cout << "]\n";
    
//     return 0;
// }


// minimum day for m bouqet k conssucative flower
// #include <bits/stdc++.h>
// using namespace std;
// #include <bits/stdc++.h>
// using namespace std;

// bool ismini(vector<int> a, int n, int s, int m, int n1) {
//     int cnt = 0;
//     int nofB = 0;
//     for(int i = 0; i < n; i++) {
//         if(a[i] <= s) {
//             cnt++;
//         } else {
//             nofB += (cnt / n1);
//             cnt = 0;
//         }
//     }
//     nofB += (cnt / n1);  // Handle the last segment
//     return nofB >= m;
// }

// int miniday(vector<int> a, int n, int m, int n1) {
//     if(n < m * n1) {
//         return -1;
//     }
    
//     int mini = *min_element(a.begin(), a.end());
//     int maxi = *max_element(a.begin(), a.end());

//     for(int i = mini; i <= maxi; i++) {
//         if(ismini(a, n, i, m, n1)) {
//             return i;
//         }
//     }
//     return -1;
// }

// int main() {
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for(int i = 0; i < n; i++) {
//         cin >> A[i];
//     }
//     int m, n1;
//     cin >> m >> n1;
//     int result = miniday(A, n, m, n1);
//     cout << result << endl;
//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// bool checkmin(vector<int> a, int n,int s, int m,int n1){
//     int cnt = 0;
//     int nofbq = 0;
//     for(int i = 0; i< n; i++){
//         if(a[i] <= s){
//             cnt++;
//         }else{
//             nofbq += (cnt/n1);
//             cnt = 0;
//         }
//     }
//     nofbq += (cnt/n1);
//     return nofbq >= m;
// }

// int miniday(vector<int> a, int n, int m,int n1){
//     if(n < m*n1) return -1;
//     int low = *min_element(a.begin(),a.end());
//     int high = *max_element(a.begin(),a.end());
//     while(low <= high){
//         int mid = low + (high-low)/2;
//         if(checkmin(a,n,mid,m,n1)){
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }
//     return low;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for(int i = 0; i < n; i++) {
//         cin >> A[i];
//     }
//     int m, n1;
//     cin >> m >> n1;
//     int result = miniday(A, n, m, n1);
//     cout << result << endl;
//     return 0;
// }

// required capacity of weight 
// #include <bits/stdc++.h>
// using namespace std;
// int reqDay(vector<int> A,int n,int cap){
//     int sum = 0;
//     int day = 1;
//     for(int i = 0; i < n; i++){
//         if(sum+A[i] > cap){
//             day += 1;
//             sum = A[i];
//         }else{
//             sum += A[i];
//         }
//     }
//     return day;
// }
// int ReqCapacity(vector<int> A,int n,int day){
//     int low = *max_element(A.begin(),A.end());
//     int high = accumulate(A.begin(),A.end(),0);

//     for(int cap = low; cap <= high;cap++){
//         if(reqDay(A,n,cap) <= day){
//             return cap;
//         }
//     }
//     return -1;
// }
// int main(){
//      int n;
//     cin >> n;
//     vector<int> A(n);
//     for(int i = 0; i < n; i++) {
//         cin >> A[i];
//     }
//     int day;
//     cin >> day;
//     int ans = ReqCapacity(A,n,day);
//     cout << ans;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int reqDay(vector<int> A,int n,int cap){
//     int sum = 0;
//     int day = 1;
//     for(int i = 0; i < n;i++){
//         if(sum+A[i] > cap){
//             day += 1;
//             sum = A[i];
//         }else{
//             sum +=A[i];
//         }
//     }
//     return day;
// }
// int ReqCapacity(vector<int> A,int n,int day){
//     int low = *max_element(A.begin(),A.end());
//     int high =accumulate(A.begin(),A.end(),0);
//     while(low < high){
//         int midcap = low + (high-low)/2;
//         if(reqDay(A,n,midcap) <= day){
//             high = midcap - 1;
//         }else{
//             low = midcap + 1;
//         }
//     }
//     return low;
// }
// int main(){
//      int n;
//     cin >> n;
//     vector<int> A(n);
//     for(int i = 0; i < n; i++) {
//         cin >> A[i];
//     }
//     int day;
//     cin >> day;
//     int ans = ReqCapacity(A,n,day);
//     cout << ans;
// }


// // Koko eating banana
// #include <bits/stdc++.h>
// using namespace std;


// int findMax(vector<int> &v) {
//     int maxi = INT_MIN;
//     int n = v.size();
//     //find the maximum:
//     for (int i = 0; i < n; i++) {
//         maxi = max(maxi, v[i]);
//     }
//     return maxi;
// }

// int findt(vector<int> &v,int h){
//     int n = v.size();
//     int t_h = 0;
//     for(int i = 0; i < n; i++){
//         t_h += ceil((double)v[i]/h);
//     }
//     return t_h;
// }


// int minimumRateToEatBananas(vector<int>& a, int h){
//     int low  = 1;
//     int high = findMax(a);
//     while(low <= high){
//         int mid = (low+high)/2;
//         if(findt(a,mid)<=h){
//             high = mid-1;
//         }else{
//             low = mid+1;
//         }
//     }
//     return low;

// }

//  int main()
// {
//     vector<int> v = {7, 15, 6, 3};
//     int h = 8;
//     int ans = minimumRateToEatBananas(v, h);
//     cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
//     return 0;
// }
// 