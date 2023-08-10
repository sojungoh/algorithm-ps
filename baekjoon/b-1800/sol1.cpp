#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, P, K;
vector<vector<pair<int, int>>> cables;

bool dijkstra(int x) {
    vector<int> dist(N + 1);
    fill(dist.begin(), dist.end(), N + 1);
    
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(dist[curr] <= cost)
            continue;
        dist[curr] = cost;
        
        for(auto p : cables[curr]) {
            int cmp = cost + (p.second > x);
            if(dist[p.first] <= cmp)
                continue;
            pq.push({-cmp, p.first});
        }
    }

    return dist[N] <= K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> K;
    
    cables.resize(N + 1);

    vector<int> cost;
    for(int i = 0; i < P; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        cables[a].push_back({b, c});
        cables[b].push_back({a, c});
        cost.push_back(c);
    }

    sort(cost.begin(), cost.end());

    int answer = -1;
    int l = 0;
    int r = N - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        
        if(dijkstra(cost[mid])) {
            if(mid == 0) {
                answer = 0;
                break;
            }
            answer = cost[mid];
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << answer << '\n';
    
    return 0;
}