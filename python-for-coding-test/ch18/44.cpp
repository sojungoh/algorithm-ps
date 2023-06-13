#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<vector<pair<int, int>>> coord(3);

struct Info {
	int weight;
	int a;
	int b;
	
	Info(int w, int _a, int _b) :
		weight(w), a(_a), b(_b)
	{}
};

struct Compare {
	bool operator() (const Info& x, const Info& y) {
		return x.weight > y.weight;
	}
};

int find_set(int *parent, int x) {
	if(parent[x] != x)
		parent[x] = find_set(parent, parent[x]);
	return parent[x];
}

void union_set(int *parent, int a, int b) {
	a = find_set(parent, a);
	b = find_set(parent, b);
	
	if(a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

void kruskal() {
	priority_queue<Info, vector<Info>, Compare> pq;
	
	int * parent = new int[n];
	for(int i = 0; i < n; ++i)
		parent[i] = i;
		
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < 3; ++j) {
			int w = abs(coord[j][i + 1].first - coord[j][i].first);
			pq.push(Info(w, coord[j][i + 1].second, coord[j][i].second));
		}
	}
	
	int ans = 0, count = 0;
	
	while(!pq.empty()) {
		int w = pq.top().weight;
		int a = pq.top().a;
		int b = pq.top().b;
		
		pq.pop();
		
		if(find_set(parent, a) == find_set(parent, b))
			continue;
		
		union_set(parent, a, b);
		ans += w;
		count++;
		
		if(count == n - 1)
			break;	
	}
	
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	int x, y, z;
	for(int i = 0; i < n; ++i) {
		cin >> x >> y >> z;
		coord[0].push_back({x, i});
		coord[1].push_back({y, i});
		coord[2].push_back({z, i});
	}
	
	for(int i = 0; i < 3; ++i)
		sort(coord[i].begin(), coord[i].end());
	
	kruskal();
	
	return 0;
}
