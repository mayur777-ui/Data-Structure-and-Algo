#include <bits/stdc++.h>
using namespace std;

// RomanTOInt
int romanToInt(string s) {
    map<char, int> mp = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int sum = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i < s.size() - 1 && mp[s[i]] < mp[s[i + 1]]) {
            sum -= mp[s[i]];
        } else {
            sum += mp[s[i]];
        }
    }

    return sum;
}

int main(){
    string s = "MCMXCIV";
    int res = romanToInt(s);
    cout << res;
}

string InttoRoman(int num) {
    map<int, string, greater<int>> mp = {
{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
{100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
{10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
};
string res = "";
for(auto &it:mp){
while(num >= it.first){
        res += it.second;
        num -= it.first;
    }
}
return res;
}

int main(){
    int num = 3749;
    string res = InttoRoman(num);
    cout << res;
}