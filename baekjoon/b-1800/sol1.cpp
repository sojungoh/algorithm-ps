#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, P, K;

void solve(vector<vector<pair<int, int>>>& cables) {
    int answer = -1;
    vector<vector<int>> dst(N + 1, vector<int>(K + 1));

    for(int i = 1; i <= N; ++i)
        fill(dst[i].begin(), dst[i].end(), int(1e7));
    
    for(int i = 0; i <= K; ++i) {
        dst[1][i] = 0;
    }

    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(auto p : cables[curr]) {
            int next = p.first;
            int cost = p.second;
            bool push_flag = false;

            // k = 0 일 때와 아닐 때
            for(int i = 0; i <= K; ++i) {
                int cmp = (i == 0) ? max(dst[curr][i], cost) : min(dst[curr][i - 1], cost);
                if(dst[next][i] <= cmp)
                    continue;
                dst[next][i] = cmp;
                push_flag = true;
            }

            if(push_flag)
                q.push(next);
        }
    }

    if(dst[N][K] < int(1e7))
        answer = dst[N][K];

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> K;
    
    vector<vector<pair<int, int>>> cables(N + 1); 
    for(int i = 0; i < P; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cables[a].push_back({b, c});
        cables[b].push_back({a, c});
    }

    solve(cables);
    
    return 0;
}