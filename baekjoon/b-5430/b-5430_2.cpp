#include <iostream>
#include <algorithm>
#include <deque>
#include <string>
#include <ctype.h>

using namespace std;

deque<int> my_parsing(const string& s) {
    deque<int> dq;
    for(int i = 1; i < s.size() - 1; ++i) {
        int cur = 0;
        while(isdigit(s[i])) {
            cur = cur * 10 + s[i] - '0';
            i++;
        }
        dq.push_back(cur);
    }
    return dq;
}

void my_print(deque<int>& dq) {
    cout << '[';
    for(deque<int>::iterator it = dq.begin(); it != dq.end(); ++it) {
        cout << *it;
        if(it + 1 != dq.end()) cout << ',';
    }
    cout << ']' << '\n';
}

void solve() {
    int n;
    string p, x;

    cin >> p >> n >> x;
    deque<int> dq = my_parsing(x);

    bool rev_flag = 0, err_flag = 0;
    for(auto& c : p) {
        if(c == 'R')
            rev_flag ^= 1;
        else if(c == 'D') {
            if(dq.empty()) { err_flag = 1; break; }
            if(rev_flag) dq.pop_back();
            else dq.pop_front();
        }
    }

    if(err_flag) cout << "error" << '\n';
    else {
        if(rev_flag) reverse(dq.begin(), dq.end());
        my_print(dq);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

    return 0;
}