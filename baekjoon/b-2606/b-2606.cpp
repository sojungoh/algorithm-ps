#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solve(int n) {
    vector<vector<int>> edges(n + 1);
    stack<int> stk;
    vector<int> visited(n + 1, 0);
    int answer = 0;
    
    int e;
    cin >> e;

    for(int i = 0; i < e; ++i) {
        int a, b;
        cin >> a >> b;

        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    stk.push(1);
    visited[1] = 1;

    while(!stk.empty()) {
        int cur = stk.top();
        stk.pop();
        
        if(cur != 1)
            answer += 1;

        for(int a : edges[cur]) {
            if(visited[a])
                continue;
            visited[a] = 1;
            stk.push(a);
        }
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    solve(n);

    return 0;
}