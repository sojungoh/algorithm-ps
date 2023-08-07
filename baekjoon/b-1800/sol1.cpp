#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

int N, P, K;

struct Info {
    int cost;
    int count;
    int idx;

    Info(int cost, int count, int idx): cost(cost), count(count), idx(idx) {}

    bool operator < (const Info& y) const {
        if(cost == y.cost)
            return count > y.count;
        return cost > y.cost;
    } 
};

void solve(vector<vector<pair<int, int>>>& cables) {
    int answer = -1;
    set<tuple<int, int, int>> check;
    priority_queue<Info> pq;
    
    pq.push(Info(0, 0, 1));
    check.insert({0, 0, 1});

    while(!pq.empty()) {
        int cost = pq.top().cost;
        int count = pq.top().count;
        int x = pq.top().idx;
        pq.pop();

        cout << cost << ' ' << count << ' ' << x << '\n';

        if(x == N) {
            answer = cost;
            break;
        }

        for(auto p : cables[x]) {
            if(count < K) {
                if(cost < p.second) {
                    if(check.find({cost, count + 1, p.first}) != check.end())
                        continue;
                    check.insert({cost, count + 1, p.first});
                    pq.push(Info(cost, count + 1, p.first));
                }
            }
            int tmp = max(cost, p.second);
            if(check.find({tmp, count, p.first}) != check.end())
                continue;
            check.insert({tmp, count, p.first});
            pq.push(Info(tmp, count, p.first));
        }
    }

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