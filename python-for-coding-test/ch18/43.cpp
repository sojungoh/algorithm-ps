#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int x;
	int weight;
	
	Info(int v, int w) :
		x(v), weight(w)
	{};
};

struct compare {
	bool operator() (const Info& a, const Info& b) {
		if(a.weight == b.weight)
			return a.x > b.x;
		return a.weight > b.weight;
	}
};

int n, m;
vector<vector<Info>> graph(200000);

void prim(int sum) {
	
	vector<int> key(n, int(2e9));
	vector<bool> isInMst(n, false);
	
	priority_queue<Info, vector<Info>, compare> pq;
	pq.push(Info(0, 0));
	
	int count = 0;
	while(!pq.empty()) {
		int w = pq.top().weight;
		int x = pq.top().x;
		pq.pop();
		
		if(isInMst[x]) continue;
		
		isInMst[x] = true;
		sum -= w;
		count += 1;
		
		if(count == n)
			break;
		
		for(Info i : graph[x]) {
			if(isInMst[i.x] || i.weight >= key[i.x])
				continue;
			
			key[i.x] = i.weight;
			pq.push(Info(i.x, i.weight));
		}
	}
	
	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	int x, y, z, sum = 0;
	for(int i = 0; i < m; ++i) {
		cin >> x >> y >> z;
		graph[x].push_back(Info(y, z));
		graph[y].push_back(Info(x, z));
		sum += z;
	}
	
	prim(sum);
	
	return 0;
}
