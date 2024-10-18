// Remove k Digits
#include<bits/stdc++.h>
using namespace std;

// approach 1
class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        
        for(char digit : num) {
            while(!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }
        
        while(k > 0) {
            result.pop_back();
            k--;
        }
        
        int idx = 0;
        while(idx < result.size() && result[idx] == '0') {
            idx++;
        }
        
        result = result.substr(idx);
        
        return result.empty() ? "0" : result;
    }
};

// approach 2


class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i = 0; i < num.length();i++){
            while(!st.empty()&&(k > 0)&&((st.top()-'0')>(num[i] - '0'))){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k > 0) {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res;
        while(!st.empty()){
            res = res + st.top();
            st.pop();
        }
        if(res.size() != 0 && res.back() == '0'){
            res.pop_back();
        }
        if(res.size() == 0)return "0";
        reverse(res.begin(),res.end());
        int idx = 0;
        while(idx < res.size() && res[idx] == '0') {
            idx++;
        }
        res = res.substr(idx);
        if(res.size() == 0) return "0";
        return res;
    }
}; 


int main(){
    Solution s;
    string num = "1432219";
    int k = 3;
    cout << s.removeKdigits(num,k) << endl;
}
