#include <iostream>

using namespace std;

int *parent;

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
	
	for(int i = 0; i <= n; ++i)
		parent[i] = i;
	
	bool is_find;
	int a, b;
	
	for(int i = 0; i < m; ++i) {
		cin >> is_find >> a >> b;
		
		if(is_find) {
			if(find_parent(a) == find_parent(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
		else
			union_parent(a, b);
	}
	
	return 0;
}
