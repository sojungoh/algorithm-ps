#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<pair<int, int>> jw;
multiset<int> bag;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i) {
        int m, v; cin >> m >> v;
        jw.push_back({v, m});
    }
    for(int i = 0; i < k; ++i) {
        int c; cin >> c;
        bag.insert(c);
    }
    sort(jw.begin(), jw.end());

    long long ans = 0;
    for(int i = n-1; i >= 0; --i) {
        if(bag.empty()) break;
        auto it = bag.lower_bound(jw[i].second);
        if(it != bag.end()) {
            bag.erase(it);
            ans += jw[i].first;
        }
    }

    cout << ans << '\n';

    return 0;
}