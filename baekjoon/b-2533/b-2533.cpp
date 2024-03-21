#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> edges;
vector<vector<int>> dp;
vector<int> vt;

void dfs(int i) {
    dp[i][0] = 1;
    dp[i][1] = 0;
    vt[i] = 1;

    for(auto v : edges[i]) {
        if(vt[v])
            continue;
        dfs(v);

        dp[i][1] += dp[v][0];
        dp[i][0] += min(dp[v][0], dp[v][1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 0;
    cin >> n;

    edges.resize(n + 1);
    vt.resize(n + 1);
    dp.resize(n + 1);
    for(int i = 0; i <= n; ++i)
        dp[i].resize(2);
    
    fill(vt.begin(), vt.end(), 0);

    for(int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1);
    ans = min(dp[1][0], dp[1][1]);

    cout << ans << '\n';

    return 0;
}