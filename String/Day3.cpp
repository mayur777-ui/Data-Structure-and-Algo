#include<bits/stdc++.h>
using namespace std;


// reverse words of string
string reverseWords(string s) {
        if(s.size() <= 0){
            return s;
        }

        string res = "";
        stack<string> st;
        for(char ch:s){
            if(ch == ' ' && res != ""){
                st.push(res);
                res = "";
            }
            if(ch != ' '){
                res += ch;
            }
        }

        if(res != ""){
            st.push(res);
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()){
                ans += " ";
            }
        }
        return ans;
}




int main(){
  string s = " Multiple spaces between words ";
  string res = reverseWords(s);
  cout << res;
}


// reverse Vowels

string reverseVowels(string s) {
    int i = 0;
    int j = s.size() - 1;
    string vowels = "aeiouAEIOU";
    while(i < j){
        while(i < j && vowels.find(s[i]) == string::npos){
            i++;
        }
        while(i < j && vowels.find(s[j]) == string::npos){
            j--;
        }

        if(i < j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    return s;
}


int main(){
  string s = "leetcode";
  string res = reverseWords(s);
  cout << res;
}


// Faulty Keyboard
string finalString(string s) {
    string res = "";
    for(char ch: s){
        if(res != "" && ch == 'i'){
            reverse(res.begin(),res.end());
            continue;
        }
        res += ch;
    }
    return res;
}

int main(){
  string s = "poiinter";
  string res = reverseWords(s);
  cout << res;
}
