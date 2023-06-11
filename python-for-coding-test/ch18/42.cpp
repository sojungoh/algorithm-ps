#include <iostream>
#include <vector>

using namespace std;

int * parent;

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
	
	int g, p;
	cin >> g >> p;
	
	parent = new int[g + 1];
	
	for(int i = 0; i <= g; ++i)
		parent[i] = i;
	
	int in, ans = 0;
	bool flag = false;
	
	for(int i = 0; i < p; ++i) {
		cin >> in;
		
		if(parent[in] == 0)
			flag = true;
		
		if(flag)
			continue;
		
		union_parent(parent[in], parent[in] - 1);
		ans++;
	}
	
	cout << ans << '\n';
	
	return 0;
}
