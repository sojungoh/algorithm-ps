#include <iostream>
#include <set>

using namespace std;

void solve() {
    multiset<int> ms;
    char c;
    int n, k; cin >> k; // 10^6
    while(k--) {
        cin >> c >> n;
        if(c=='I') ms.insert(n);
        else if(c=='D') {
            if(ms.empty()) continue;
            if(n==1) ms.erase(prev(ms.end()));
            else if(n==-1) ms.erase(ms.begin());
        }
    }

    if(ms.empty()) cout << "EMPTY\n";
    else cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}