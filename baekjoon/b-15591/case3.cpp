#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using pii = pair<int, int>;

int N, Q;

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

    vector<vector<pii>> query(N + 1);
    for(int i = 0; i < Q; ++i) {
        int k, v;
        cin >> k >> v;
        query[v].push_back({k, i});
    }

    for(auto& vec : query)
        sort(vec.rbegin(), vec.rend());

    vector<int> ans(Q, 0);
    for(int v = 1; v <= N; ++v) {
        if(query[v].empty())
            continue;
        
        vector<bool> visited(N + 1, false);
        int sum = 0;
        int checkpoint = v;
        for(auto [k, i] : query[v]) {
            ans[i] += sum;

            queue<int> que;
            que.push(checkpoint);
            
            sum = 0;
            while(!que.empty()) {
                int curr = que.front();
                que.pop();

                if(curr != checkpoint && visited[curr])
                    continue;
                visited[curr] = true;

                for(auto [q, r] : graph[curr]) {
                    if(r < k) {
                        checkpoint = curr;
                        continue;
                    }
                    sum += 1;
                    que.push(q);
                }
            }
            ans[i] += sum;
        }
    }

    for(int a : ans)
        cout << a << '\n';

    return 0;
}