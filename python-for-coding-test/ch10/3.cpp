#include <iostream>
#include <queue>

using namespace std;

int * parent;

struct road_info {
	int cost;
	int a;
	int b;
	
	road_info(int _c, int _a, int _b) :
		cost(_c), a(_a), b(_b)
	{}
};

struct compare {
	bool operator() (const road_info& s1, const road_info& s2) {
		return s1.cost > s2.cost;
	}
};

int find_parent(int x) {
	if(parent[x] != x)
		parent[x] = find_parent(parent[x]);
	return parent[x];
}

void union_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);
	
	if(a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	parent = new int[n + 1];
	for(int i = 0; i < n + 1; ++i)
		parent[i] = i;
		
	priority_queue<road_info, vector<road_info>, compare> pq;
	
	int a, b, c;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		
		pq.push(road_info(c, a, b));
	}
	
	int ans = 0, count = 0;
	while(!pq.empty()) {
		a = pq.top().a;
		b = pq.top().b;
		c = pq.top().cost;
		pq.pop();
		
		if(count == n - 2)
			break;
		
		if(find_parent(a) != find_parent(b)) {
			ans += c;
			count++;
			union_parent(a, b);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
