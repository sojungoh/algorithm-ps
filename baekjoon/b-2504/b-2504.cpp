#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    int ans = 0, num = 1;

    stack<char> stk;
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '(') {
            stk.push(s[i]);
            num *= 2;
        }
        else if(s[i] == '[') {
            stk.push(s[i]);
            num *= 3;
        }
        else if(s[i] == ')') {
            if(stk.empty() || stk.top() != '(') {
                ans = 0;
                break;
            }
            if(s[i - 1] == '(') { ans += num; }
            stk.pop();
            num /= 2;
        }
        else if(s[i] == ']') {
            if(stk.empty() || stk.top() != '[') {
                ans = 0;
                break;
            }
            if(s[i - 1] == '[') { ans += num; }
            stk.pop();
            num /= 3;
        }
    }

    if(!stk.empty())
        ans = 0;

    cout << ans << '\n';

    return 0;
}