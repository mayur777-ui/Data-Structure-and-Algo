// Reverse a String
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i = 0;
    int j = s.size()- 1;
    while(i <= j){
        swap(s[i],s[j]);
        i++;
        j--;
    }   
    cout << s;
}


// Check Palindorom
int main()
{
    string s;
    cin >> s;
    int i = 0; 
    int j = s.size() - 1;
    bool flag = false;
    while(i <= j){
        if(s[i] != s[j]){
            flag = true;
            break;
        }
        i++;
        j--;
    }
    if(flag){
        cout << s << " is not palindrom string";
    }else{
        cout << s << " is a palindrom string";
    }
}



// Count vowels and consonants 

int main(){
    string s;
    cin >> s;
    int vcnt = 0;
    int ccnt = 0;
    for(char ch:s){
        ch = tolower(ch);
        if(ch >= 'a' && ch <= 'z'){
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vcnt++;
            }else{
                ccnt++;
            }
        }
    }
    cout << "Vowels: " << vcnt << endl;
    cout << "Consonants: " << ccnt << endl;
}


// Largest and shortest method
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s); 
    
    string largest = "", smallest = "", word;
    stringstream ss(s);  // Break string in word
    
    ss >> word; // First word 
    smallest = largest = word;

    while (ss >> word) { 
        if (word.size() > largest.size()) {
            largest = word;
        }
        if (word.size() < smallest.size()) {
            smallest = word;
        }
    }    
    cout << "Largest word: " << largest << endl;
    cout << "Smallest word: " << smallest << endl;

    return 0;
}



// // Understading the find function within c++

int main(){
    string str = "this is a sample string";
    string substr = "sample";

    size_t pos = str.find(substr);
    if(pos != string::npos){
        cout << "Substring found at index: " << pos << endl;
    }else{
        cout << "Substring not found." << endl;
    }

   string str = "Hello, Hello, World!";

    size_t index = str.find("Hello", 6);

    if (index != string::npos) {
        cout << "'Hello' found at index: " << index << endl;
    } else {
        cout << "'Hello' not found." << endl;
    }

    string str = "Hello, Hello, World!";
    string target = "Hello";

    size_t pos = str.find(target);
    while (pos != string::npos) {
        cout << "'" << target << "' found at index: " << pos << endl;
        pos = str.find(target, pos + 1);
    }

}

// Defanging an IP Address
#include<bits/stdc++.h>
using namespace std;
string defangIPaddr(string address) {
    string res = "";
    for(char ch:address){
        if(ch == '.'){
            res += "[" + string(1,ch) + "]";
            // res += "[.];"
        }else{
            res += ch;
        }
    }
    return res;
}

int main(){
    string s;
    getline(cin,s);
    string res = defangIPaddr(s);
    cout << res;
}


#include<bits/stdc++.h>
using namespace std;

// Approach 1;
bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        for(int i = 0; i < s.size(); i++){
            char ch = s[0];
            s.erase(s.begin());
            s.push_back(ch);
            if(s == goal) return true;
        }
        return false;
}

// Approach 2
// explanation=> if we do s+s then all of rotation of s is substring of s+s 

bool rotateString(string s, string goal){
    if(s.size() != goal.size()){
        return false;
    }
    string con = s + s;
    return con.find(goal) != string::npos;
}
int main(){
    string s;
    getline(cin,s);
    string g;
    getline(cin,g);
    if( rotateString(s,g)){
        cout << "after certain rotation \"" << s << "\" can be " << g;
    }else{
        cout << "can't obtain " << g << "on certain left rotation on " << s;
    }
}




// check Pangram
#include<bits/stdc++.h>
using namespace std;
bool checkIfPangram(string sentence) {
    if(sentence.size() < 26){
        return false;
    }
    bool flag = false;
    for(char ch : sentence){
        if(ch >= 'a' && ch <= 'z'){
            flag = true;
        }else{
            return false;
        }
    }
    return flag;
}


int main(){
    string s;
    cin >> s;
    if(checkIfPangram(s)){
        cout << "true";
    }else{
        cout << "false";
    }
}