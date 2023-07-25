#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, Q;

int bfs(vector<vector<pii>>& g, int k, int v) {
    queue<int> que;
    que.push(v);
    vector<bool> visited(N + 1, false);

    int ans = -1;
    while(!que.empty()) {
        int curr = que.front();
        que.pop();

        if(visited[curr])
            continue;
        visited[curr] = true;
        ans += 1;

        for(auto [q, r] : g[curr]) {
            if(r < k)
                continue;
            que.push(q);
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    vector<vector<pii>> graph(N + 1);
    for(int i = 0; i < N - 1; ++i) {
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }

    vector<pii> query(Q);
    for(int i = 0; i < Q; ++i) {
        int k, v;
        cin >> k >> v;
        query[i] = {k, v};
    }

    for(auto [k, v] : query)
        cout << bfs(graph, k, v) << '\n';
    
    return 0;
}