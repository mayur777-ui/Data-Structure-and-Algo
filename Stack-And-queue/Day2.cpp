// Check for Balanced Parentheses
#include <bits/stdc++.h>
using namespace std;
bool isValid(string s){
    stack<char> st;
    for(auto it:s){
        if(it == '(' || it == '[' || it == '{'){
            st.push(it);
        }else{
            if(st.empty()){
                return false;
            }
            char ch = st.top();
            st.pop();
            if((it == ')' && ch == '(') || (it == ']' && ch == '[') || (it == '}' && ch == '{')){
                continue;
            }else{
                return false;
            }
        }
    }
    return st.empty();
};

int main()
{
    string s="()[{}()]";
    if(isValid(s))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}


// Implement Min Stack 
// Approach 1
#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        long long newval = static_cast<long long>(val);
        if(st.empty()) { 
            st.push(newval);
            mini = newval;
        } else {
            if(newval < mini) {
                st.push(2 * newval - mini);
                mini = newval;
            } else {
                st.push(newval);
            }
        }
    }

    long long pop() {
        if(st.empty()) return -1;
        long long el = st.top();
        st.pop();
        if(el < mini) {
            mini = 2 * mini - el;
        }
        return el;
    }

    int top() {
        if(st.empty()) return -1;
        long long el = st.top();
        if(el < mini) {
            return static_cast<int>(mini);
        }
        return static_cast<int>(el);
    }

    int getMin() {
        return static_cast<int>(mini);
    }
};



// Approch2
class MinStack {
  stack < pair < int, int >> st;

  public:
    void push(int x) {
      int min;
      if (st.empty()) {
        min = x;
      } else {
        min = std::min(st.top().second, x);
      }
      st.push({x,min});
    }

  void pop() {
    st.pop();
  }

  int top() {
    return st.top().first;
  }

  int getMin() {
    return st.top().second;
  }
};



int main() {
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->push(3);
    obj->push(7);
    cout << "Top: " << obj->top() << endl;
    cout << "Min: " << obj->getMin() << endl;
    cout << "Popped: " << obj->pop() << endl;
    cout << "Top after pop: " << obj->top() << endl;
    cout << "Min after pop: " << obj->getMin() << endl;
    cout << "Popped: " << obj->pop() << endl;
    cout << "Min after another pop: " << obj->getMin() << endl;
    delete obj;
    return 0;
}
