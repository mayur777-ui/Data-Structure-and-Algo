#include <bits/stdc++.h>
using namespace std;


// 1.Approach 1(two loop broute force)
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

// Approach 2 (optimal with two pointer)
int lengthOfLongestSubstring(string s) {
    int l = 0;
    unordered_set <char> set;
    int maxSize = 0;
    for(int r = 0; r < s.length(); r++){
        if(set.find(s[r]) != set.end()){
            while(l < r && set.find(s[r]) != set.end()){
                set.erase(s[l]);
                l++;
            }
        }
        set.insert(s[r]);
        maxSize = max(maxSize, r - l + 1);
    }
    return maxSize;
}    


int main() {
    string s;
    cin >> s;
    cout << "The length of the longest substring without repeating characters is " 
         << lengthOfLongestSubstring(s) << endl;
    return 0;
}
