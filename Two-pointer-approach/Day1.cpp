#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.length() == 0){
        return 0;
    }
    int len = 0;
    for(int i = 0; i < s.length(); i++){
        unordered_set<int> set;
        for(int j = i; j < s.length(); j++){
            if(set.find(s[j]) != set.end()){
                len = max(len, j - i);
                break;
            }
            set.insert(s[j]);
        }
    }
    return len;
}

int main() {
    string s;
    cin >> s;
    cout << "The length of the longest substring without repeating characters is " 
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
