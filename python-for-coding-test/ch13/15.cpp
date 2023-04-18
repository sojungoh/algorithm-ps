#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k, x, visited[300001] = {0, };
vector<vector<int>> city(300001);
priority_queue<int> answer;
priority_queue<pair<int, int>> pq;

void solve() {
	
	pq.push({-0, x});
	visited[x] = 1;
	
	while(!pq.empty()) {
		int dist = -pq.top().first;
		int city_num = pq.top().second;
		pq.pop();
		
		if(dist == k)
			answer.push(-city_num);
		
		if(dist > k)
			break;
		
		for(int v : city[city_num]) {
			if(visited[v]) 
				continue;
			visited[v] = 1;
			pq.push({-(dist + 1), v});
		}
	} 
	
	if(answer.empty()) {
		cout << -1 << endl;
		return;
	}
	
	while(!answer.empty()) {
		cout << -answer.top() << endl;
		answer.pop();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m >> k >> x;
	
	int a, b;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		city[a].push_back(b);
	}
	
	solve();
	
	return 0;
}
