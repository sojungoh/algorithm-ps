#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, C;
priority_queue<pair<int, int>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    vector<int> x(N), y(N), cost(N);
    for(int i = 0; i < N; ++i) {
        cin >> x[i] >> y[i];
        cost[i] = int(1e9);
    }

    vector<bool>visited(N, false);
    cost[0] = 0;
    pq.push({0, 0});

    int ans = 0, count = 0;
    while(!pq.empty()) {
        int c = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(visited[curr])
            continue;
        visited[curr] = true;
        ans += c;
        count++;

        if(count == N)
            break;

        for(int i = 0; i < N; ++i) {
            if(i == curr) continue;

            int tmp = pow(x[curr] - x[i], 2) + pow(y[curr] - y[i], 2);
            if(tmp < C || tmp > cost[i]) continue;
            
            cost[i] = tmp;
            pq.push({-cost[i], i});
        }
    }

    if(count != N) 
        ans = -1;
    
    cout << ans << '\n';

    return 0;
}