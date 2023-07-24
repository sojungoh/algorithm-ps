#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
using tti = tuple<int, int, int>;

int N, Q;

bool cmp(const tti& a, const tti& b) {
	return get<0>(a) > get<0>(b);	
}

int find_parent(vector<int>& p, int a) {
	if(p[a] < 0)
		return a;
	return p[a] = find_parent(p, p[a]);
}

void union_parent(vector<int>& p, int a, int b) {
	a = find_parent(p, a);
	b = find_parent(p, b);

	if(a == b)
		return;

	p[b] += p[a];
	p[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> Q;

	vector<tti> graph(N - 1);
	for(int i = 0; i < N - 1; ++i) {
		auto& [r, p, q] = graph[i];
		cin >> p >> q >> r;
	}
	
	vector<tti> query(Q);
	for(int i = 0; i < Q; ++i) {
		auto& [k, v, idx] = query[i];
		cin >> k >> v;
		idx = i;
	}

	sort(graph.begin(), graph.end(), cmp);
	sort(query.begin(), query.end(), cmp);

	vector<int> parent(N + 1, -1);
	vector<int> ans(Q);
	int count = 0;
	for(auto [k, v, idx] : query) {
		while(count < N - 1) {
			auto [r, p, q] = graph[count];
			if(r >= k) {
				union_parent(parent, p, q);
				++count;
			}
			else
				break;
		}
		int p = find_parent(parent, v);
		ans[idx] = -(parent[p] + 1);
	}

	for(int a : ans)
		cout << a << '\n';

	return 0;
}
