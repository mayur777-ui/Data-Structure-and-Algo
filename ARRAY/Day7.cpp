#include <iostream>
#include <bits/stdc++.h>
using namespace std;



// NUMBER FREQUENCY with given queries
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int hash[100] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1; 
    }
    int q;
    cin >> q;
    int i = 0;
    while( q--){
        int num;
        cin >> num;

        cout<< num << "  " << hash[num] << endl;
    }
}

// number frequency
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int hash[100] = {0};
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1; 
    }
    bool printed[100] = {false};
    for(int i = 0; i < n; i++){
        if(!printed[arr[i]]){
            cout << arr[i]<< " " << hash[arr[i]] << endl;
            printed[arr[i]] = true;
        }
    }
}



//  for lower case character freaquency 
int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    int hash[26] = {0};  // Array to hold frequencies of each letter

    // Count frequency of each character
    for (int i = 0; i < n; i++) {
        hash[s[i] - 'a'] += 1;
    }

    bool printed[26] = {false};  // Array to track printed characters

    // Print frequency of each unique character
    for (int i = 0; i < n; i++) {
        if (!printed[s[i] - 'a']) {
            cout << s[i] << ": " << hash[s[i] - 'a'] << endl;
            printed[s[i] - 'a'] = true;
        }
    }

    cout << endl;  // Newline at the end of output
    return 0;
}



// for mixed lower + upper both

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int hash[256] = {0};
    for(int i = 0; i < n; i++){
        hash[s[i]] += 1;
    }
    bool printed[256] = {false};
    for(int i = 0; i < n; i++){
        if(!printed[s[i]]){
            cout << s[i] << ": " << hash[s[i]] << endl;
            printed[s[i]] = true;
        }
    }
}

// using map function

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    map<int, int> m;
    for(int i = 0; i < n; i++){
        m[arr[i]]++;
    }
    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetch:
        cout << m[number] << endl;
    }
}


// to print all subarray of given array 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 0, 5, 2};
    int n = arr.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "[";
            for (int k = i; k <= j; k++) {
                cout << arr[k];
                if (k != j) cout << ", "; 
            }
            cout << "] ";
        }
        cout << endl; 
    }

    return 0;
}
 
