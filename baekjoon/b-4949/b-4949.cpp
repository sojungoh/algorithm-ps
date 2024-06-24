#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    while(true) {
        string s;
        stack<char> stk;
        bool err_flag = 0;
        getline(cin, s, '.');

        if(s.size() == 1) break;
        
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(err_flag) continue;
            if(c == '(' || c == '[') { stk.push(c); }
            else if(c == ')') {
                if(stk.empty() || stk.top() != '(') err_flag = 1;
                else stk.pop();
            }
            else if(c == ']') {
                if(stk.empty() || stk.top() != '[') err_flag = 1;
                else stk.pop();
            }
        }
        if(!err_flag && stk.empty()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}