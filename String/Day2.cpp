#include<bits/stdc++.h>
using namespace std;


// // Longest Common Prefix (LCP)



// // Approach 1.
// string LongestCommonPrefix(vector<string> strs, int n){
//     if(strs.empty()){
//         return "";
//     }
//     sort(strs.begin(),strs.end());
//     string first = strs[0];
//     string last = strs[n - 1];
//     int i = 0;
//     while(i < first.size() && i < last.size() && first[i] == last[i]){
//         i++;
//     }

//     return first.substr(0,i);

// }



// // Approach 2.(using divide and conquer)


// string commonPrefix(string left,string right){
//     int i = 0;
//     while(i < left.size() && i < right.size() && left[i] == right[i]){
//         i++;
//     }

//     return left.substr(0,i);
// }
// string LongestCommonPrefix(vector<string>&strs,int low,int high){
//     if(low == high){
//         return strs[low];
//     }
//     int mid = (low + high)/2;
//     string left = LongestCommonPrefix(strs,low,mid);
//     string right = LongestCommonPrefix(strs,mid + 1,high);

//     return commonPrefix(left,right);
// }


// int main(){
//     int n = 5;
//     vector<string> strs(n);
//     for (int i = 0; i < n; i++) {
//         cin >> strs[i];
//     }

//     string LCP = LongestCommonPrefix(strs, 0, n - 1);
//     cout << LCP;
// }





// #include<bits/stdc++.h>
// using namespace std;

// string customSortString(string order, string s) {
//     unordered_map<char,int> freq;
//     for(char ch : s){
//         freq[ch]++;
//     }
//     string res = "";
//     for(char ch:order){
//         while(freq[ch] > 0){
//             res += ch;
//             freq[ch]--;
//         }
//     }

//     for(char ch : s){
//         while(freq[ch] > 0){
//             res += ch; 
//             freq[ch]--;
            
//         }
//     }
//     return res;
// }

// int main(){
//     string order,s;
//     cin >> order >> s;
//     string res = customSortString(order,s);
//     cout << res;
// }


// Approach 1

int minAddToMakeValid(string s) {
    int n = s.size();
    // int size = n;
    stack<char> st;
    for(int i = 0; i < n; i++){
        if(!st.empty() && s[i] == ')' && st.top() == '('){
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
     return st.size();
}


// Approach 2
int minAddToMakeValid(string s) {
    int open = 0, close = 0;
    
    for (char ch : s) {
        if (ch == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    
    return open + close;
}

int main(){
    string s;
    cin >> s;
    int res = minAddToMakeValid(s);
    cout << res;
}