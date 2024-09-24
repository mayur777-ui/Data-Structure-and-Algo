
// pascal triangle 
// 1.to find only no at position
// #include<iostream>
// using namespace std;

// void findnthpascalnumber(int r,int c){
//     long long res = 1;
//     for(int i = 0; i < c; i++){
//         res = res * (r - i);
//         res = res / (i+1);
//     }
//     cout << res << endl;
// }
// int main(){
//     int r;
//     int c;
//     cin >> r >> c;
//     findnthpascalnumber(r - 1,c - 1);
// }


// 2. to find given row
// broute Approach-:  
// #include<iostream>
// using namespace std;

// int findpascalno(int r,int c){
//     long long res = 1;
//     for(int i = 0; i < c; i++){
//         res = res * (r - i);
//         res = res/(i  +1);
//     }
//     return res;
// }
// void findpascalrow(int r){
//     for(int i = 1; i <= r; i++){
//         cout << findpascalno(r - 1, i - 1) << " ";
//     }
// }
// int main(){
//     int r;
//     cin >> r;
//     findpascalrow(r);

// }

// Optimal Approach
// #include<iostream>
// using namespace std;
// void pascalTriangle(int r){
//     long long res = 1;
//      cout << res << " ";
//     for(int col = 1; col < r; col++){
//         res = res * (r - col);
//         res = res/col;
//         cout << res << " ";
//     }
// }


// int main()
// {
//     int n = 5;
//     pascalTriangle(n);
//     return 0;
// // }


// 3 to find whole pascal triangle
// int  findpascalno(int r,int c){
//     long long res = 1;
//     for(int i = 0; i < c; i++){
//         res = res * (r - i);;
//         res = res/(i + 1);
//     }
//     return res;
// }


// void findpascal(int r){
//     for(int i = 0; i <= r; i++){
//         cout << findpascalno(r, i) << " ";
//     }
// }

// #include<iostream>
// using namespace std;

// int main(){
//     int r;
//     cin >> r;
//     for(int i = 0; i < r; i++){
//         findpascal(i);
//         cout << endl;
//     }
// }




// #include<bits/stdc++.h>
// using namespace std;
// vector<int> pascalTrianglerow(int r){
//     long long res = 1;
//     vector<int> ans;
//     ans.push_back(res);
//     for(int col = 1; col < r; col++){
//         res = res * (r - col);
//         res = res/col;
//         ans.push_back(res);
//     }

//     return ans;
// }
// vector<vector<int>>pascalTriangle(int r){
//     vector<vector<int>> ans;
//      for (int row = 1; row <= r; row++){
//         ans.push_back(pascalTrianglerow(row));
//     }
//     return ans;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> ans = pascalTriangle(n);
//     for(auto it : ans){
//         for(auto ele: it){
//             cout << ele << " ";
//         }
//         cout << endl;
//     }
// }


// #include <iostream>
// #include <cmath> // For abs function
// using namespace std;

// int main() {
//     int n;
//     cin >> n; // Read the number of checkpoints

//     int packages[n]; // Array for number of packages at each checkpoint
//     int thresholds[n - 1]; // Array for threshold values

//     // Read the number of packages at each checkpoint
//     for (int i = 0; i < n; i++) {
//         cin >> packages[i];
//     }

//     // Read the threshold values
//     for (int i = 0; i < n - 1; i++) {
//         cin >> thresholds[i];
//     }

//     int count = 0; // Initialize count of valid changes

//     // Calculate absolute changes and compare with thresholds
//     for (int i = 0; i < n - 1; i++) {
//         int change = abs(packages[i + 1] - packages[i]); // Calculate absolute change
//         if (change >= thresholds[i]) { // Check if it meets the threshold
//             count++; // Increment count if condition is met
//         }
//     }

//     // Output the result
//     cout << count << endl;

//     return 0;
// }
