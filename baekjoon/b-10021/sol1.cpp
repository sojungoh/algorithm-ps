#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Info {
    int f1;
    int f2;
    int cost;

    Info(int f1, int f2, int cost): f1(f1), f2(f2), cost(cost) {}

    bool operator < (const Info& a) const {
        return cost > a.cost;
    }
};

int N, C;
priority_queue<Info> pq;

int find_group(vector<int>& p, int a) {
    if(p[a] != a)
        p[a] = find_group(p, p[a]);
    return p[a];
}

void union_group(vector<int>& p, int a, int b) {
    a = find_group(p, a);
    b = find_group(p, b);

    if(a == b)
        return;
    
    if(a > b)
        p[a] = b;
    else
        p[b] = a;
}

long long kruskal() {
    vector<int> p(N + 1);
    for(int i = 0; i <= N; ++i)
        p[i] = i;

    long long ans = 0;
    int count = 0;
    while(!pq.empty()) {
        int f1 = pq.top().f1;
        int f2 = pq.top().f2;
        int c = pq.top().cost;

        pq.pop();

        if(find_group(p, f1) == find_group(p, f2))
            continue;
        
        union_group(p, f1, f2);
        ans += c;
        count += 1;

        if(count == N - 1)
            break;
    }

    if(count != N - 1)
        ans = -1;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    vector<pair<int, int>> coord(N);
    for(int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        coord[i] = {x, y};
    }

    for(int i = 0; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            int x1 = coord[i].first;
            int y1 = coord[i].second;
            int x2 = coord[j].first;
            int y2 = coord[j].second;

            int cost = pow(x2 - x1, 2) + pow(y2 - y1, 2);

            if(cost < C)
                continue;
        
            pq.push(Info(i, j, cost));
        }
    }

    cout << kruskal() << '\n';

    return 0;
}