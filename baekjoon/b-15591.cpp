#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int N, Q;
vector<vector<pii>> graph(5001);

int solve(int k, int v) {
	
	int *usado = new int[N + 1];
	fill(usado, usado + N + 1, int(1e9) + 1);
	
	queue<int> q;
	q.push(v);
	
	while(!q.empty()) {
		int curr = q.front();
		q.pop();
		
		for(pii p : graph[curr]) {
			if(p.first == v || usado[p.first] <= int(1e9))
				continue;
				
			usado[p.first] = min(p.second, usado[curr]);
			q.push(p.first);
		}
	}
	
	int ret_val = 0;
	for(int i = 1; i <= N; ++i) {
		if(i == v) continue;
		
		if(usado[i] >= k)
			ret_val += 1;
	}
	
	free(usado);
	
	return ret_val;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> Q;
	
	int p, q, r;
	for(int i = 0; i < N - 1; ++i) {
		cin >> p >> q >> r;
		graph[p].push_back({q, r});
		graph[q].push_back({p, r});
	}
	
	int k, v;
	while(Q--) {
		cin >> k >> v;
		cout << solve(k, v) << '\n';
	}
	
	return 0;
}
