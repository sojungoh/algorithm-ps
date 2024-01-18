#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    string s; 
    cin >> s;
    
    int ans = 0;
    stack<char> stk;
    
    for(int i = 0; i < s.size(); ++i) {
        if(i != s.size() - 1 && s[i] == '(' && s[i + 1] == ')') { // laser
            ans += stk.size();
            i++;
            continue;
        }

        if(s[i] == '(') stk.push('(');
        else if(s[i] == ')') {
            ans += 1;
            stk.pop();
        }
    }

    cout << ans << '\n';

    return 0;
}