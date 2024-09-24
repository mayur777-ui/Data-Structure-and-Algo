
// Set to be metrix zero 
// #include<iostream>
// #include<vector>
// using namespace std;

// void makecol(vector<vector<int>>& a, int n, int j) {
//     for(int i = 0; i < n; i++) {
//         if(a[i][j] != 0) {
//             a[i][j] = 1;
//         }
//     }
// }

// void makeRow(vector<vector<int>>& a, int m, int i) {
//     for (int j = 0; j < m; j++) {
//         if(a[i][j] != 0) {
//             a[i][j] = 1;
//         }
//     }
// }

// vector<vector<int>> zeroMatrix(vector<vector<int>>& a, int n, int m) {
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(a[i][j] == 0) {
//                 makecol(a, n, j);
//                 makeRow(a, m, i);
//             }
//         }
//     }

//     // Convert all -1 values to 0
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(a[i][j] == -1) {
//                 a[i][j] = 0;
//             }
//         }
//     }

//     // return a; // Returning the updated matrix
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
    
//     vector<vector<int>> a(n, vector<int>(m));
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cin >> a[i][j];
//         }
//     }

//     // Get the modified matrix after calling zeroMatrix
//     vector<vector<int>> ans = zeroMatrix(a, n, m);

//     // Print the result matrix
//     for(const auto& row : ans) {
//         for(const auto& elem : row) {
//             cout << elem << " ";
//         }
//         cout << endl; // Print newline after each row
//     }

//     return 0;
// }


// BETTER SOLUTION
#include<bits/stdc++.h>
using namespace std;

// vector<vector<int>> zeroMatrix(vector<vector<int>>& a, int n, int m) {
//     // Use vectors to store which rows and columns need to be zeroed out
//     vector<int> row(n, 0); // Initialize a row array of size n with all 0
//     vector<int> col(m, 0); // Initialize a col array of size m with all 0

//     // First pass to mark the rows and columns that should be zeroed
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(a[i][j] == 0) {
//                 row[i] = 1;
//                 col[j] = 1;
//             }
//         }
//     }

//     // Second pass to update the matrix based on the row and column markers
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             if(row[i] == 1 || col[j] == 1) {
//                 a[i][j] = 0;
//             }
//         }
//     }

//     return a; // Return the modified matrix
// }

// int main() {
//     int n, m;
//     cin >> n >> m;
    
//     vector<vector<int>> a(n, vector<int>(m));
//     for(int i = 0; i < n; i++) {
//         for(int j = 0; j < m; j++) {
//             cin >> a[i][j];
//         }
//     }

//     // Get the modified matrix after calling zeroMatrix
//     vector<vector<int>> ans = zeroMatrix(a, n, m);

//     // Print the result matrix
//     for(const auto& row : ans) {
//         for(const auto& elem : row) {
//             cout << elem << " ";
//         }
//         cout << endl; // Print newline after each row
//     }

//     return 0;
// }


// int main(){
//     long long a;
//     long long fact = 1;
//     cin >> a;
//     for(long long i = 1; i <= a; i++){
//         fact *= i;
//     }
//     cout << fact << endl;
// }

// int main(){
//     int n;
//     cin >> n;
//     int arr1[n][n];
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cin >> arr1[i][j];
//         }
//     }
//     int arr2[n][n];
//     for(int i = 0; i < n; i++){
//         for(int j= 0; j < n; j++){
//             arr2[j][n-1-i] = arr1[i][j];
//         }
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             cout <<arr2[i][j] << " ";
            
//         }cout << endl;

//     }

// }
