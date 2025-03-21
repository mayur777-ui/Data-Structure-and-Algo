
// #include<bits/stdc++.h>
// using namespace std;

// // //  String Matching algorithms



// // 1.Brute force string matching algo 


// // int findIndexofpattern(string T,string p){
// //     int n = T.size();
// //     int m = p.size();

// //     if(m > n){
// //         return  -1;
// //     }

// //     for(int i = 0; i <= n - m; i++){
// //         int j;
// //         for(j = 0; j < m; j++){
// //             if(T[i + j] != p[j]){
// //                 break;
// //             }
// //         }

// //         if(j == m){
// //             return i;
// //         }
// //     }
// //     return -1;
// // }

// // int main(){
// //     string T = "HELLOHELLO";
// //     string p = "LO";

// //     int res = findIndexofpattern(T,p);
// //     cout << res;

// // }



// // Longest Happy prefix sum problem 

// string longestPrefix(string s) {
//     int m = s.size();
//     vector<int> lps(m, 0);
//     int i = 0;

//     for (int j = 1; j < m; j++) {
//         if (s[i] == s[j]) {
//             i++;
//             lps[j] = i;
//         } else {
//             if (i != 0) {
//                 i = lps[i - 1];
//                 j--;
//             }
//         }
//     }

//     return s.substr(0, s.substr(0,lps[m - 1]);
// }

// int main() {
//     string s = "acccbaaacccbaac";
//     string res = longestPrefix(s);
//     cout << "Longest happy prefix: " << res << endl;
//     return 0;
// }




// // knuth-morris-pratt (kmp) algorithm


// vector<int>longestPrefixSufix(string p){
//     int m = p.size();
//     int i = 0; 
//     vector<int>lps(m, 0);
//     for (int j = 1; j < m; j++) { 
//         if (p[i] == p[j]) {
//             i++;
//             lps[j] = i;
//         } else {
//             if (i != 0) {
//                 i = lps[i - 1]; 
//                 j--; 
//             }
//         }
//     }
//     return lps;
// }

// vector<int> searchformatchingPattern(string s,string p){
//     int n = s.size();
//     int m = p.size();
//     vector<int> lps = longestPrefixSufix(p);
//     vector<int> res;
//     int i = 0,j = 0;
//     while(i < n){
//         if(s[i] == p[j]){
//             i++;
//             j++;
//         }
//         if(j == m){
//             res.push_back(i - j);
//             j = lps[j - 1];
//         }
//         else if(i < n &&s[i] != p[j] )
//         {
//             if(j != 0){
//                 j = lps[j - 1];
//             }else{
//                 i++;
//             }
//         }
//     }
//     return res;
// }

// int main(){
//     string s = "ABABABCABABABCABABABC";
//     string p = "ABABABC";
//     vector<int> res = searchformatchingPattern(s,p);
//     for(int i = 0; i < res.size(); i++){
//         cout << res[i] << " ";
//     }
// }