#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> edges;
vector<int> vt;
int answer = -1;

void dfs(int cur) {
    answer += 1;

    for(int a : edges[cur]) {
        if(vt[a] == 1)
            continue;
        vt[a] = 1;
        dfs(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    edges.resize(n + 1);
    vt.resize(n + 1);
    fill(vt.begin(), vt.end(), 0);

    int e;
    cin >> e;
    for(int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);  
    }

    vt[1] = 1;
    dfs(1);

    cout << answer << '\n';

    return 0;
}