<<<<<<< HEAD
//1. INFIX TO POstFIX;
=======
// INFIX TO POSTFIX;
>>>>>>> 2741e02c16407fb5382220c739e79e0d61b8b8d9
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





//2. INFIX TO PreFIX;

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

void prefixToPostfix(string s){
    stack<char> st;
    string post = "";
    reverse(s.begin(),s.end());

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(isalnum(ch)){
            post = post + ch;
        }else if(ch == '('){
            st.push(ch);
        }else if(ch == ')'){
            while(st.top()!='('){
                post = post + st.top();
                st.pop();
            }
            st.pop();
        }else{
            while(!st.empty() && prec(ch) <= prec(st.top())){
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
    reverse(post.begin(),post.end());
    cout<< "After conversion to prefix is:" << post<<endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  prefixToPostfix(exp);
  return 0;
}





//3. POSTFIX TO INFIX
void PostfixToinfix(string s) {
    stack<string> st;
    int i = 0;
    int n = s.length();
    while(i < n) {
        if(isalnum(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string ex = '(' + t2 + s[i] + t1 + ')';
            st.push(ex);
        }
        i++;
    }
    cout << "The conversion is: " << st.top() << endl;
}

int main() {
    string exp = "AB+C*";
    cout << "Postfix expression: " << exp << endl;
    PostfixToinfix(exp);
    return 0;
}