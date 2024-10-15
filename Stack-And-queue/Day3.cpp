// INFIX TO POSTFIX;
#include<bits/stdc++.h>
using namespace std;
int prec(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 2;
    }else if(c == '^'){
        return 3;
    }else{
        return -1;
    }
}

void infixToPostfix(string s){
    stack<char> st;
    int i = 0;
    string post = "";
    // int n = s.length();
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if((ch >= 'A' && ch  <= 'Z') || (ch  >= 'a' && ch <= 'z') || (ch  >= '0' && ch  <= '9')){
            post = post + ch;
        }else if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            while(st.top() != '('){
                post = post + st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty()&&prec(ch) <= prec(st.top())){
                post = post + st.top();
                st.pop();
            }
            st.push(ch);
        }
        
    }

    while(!st.empty()){
        post = post + st.top();
        st.pop();
    }

    cout << "PostFix Conversion is: " << post;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}
