#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, ans = 0;
	
	cin >> n;
	
	int a;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		pq.push(-a);
	}
	
	if(pq.size() < 2) {
		ans = 0;
	}
	else {	
		for(int i = 0; i < 2; ++i) {
			ans += -pq.top();
			pq.pop();
		}
	
		pq.push(-ans);
		
		int first = 0;
		while(!pq.empty()) {
			if(!first) {
				first = -pq.top();
				pq.pop();
				continue;
			}
			
			int sum = first - pq.top();
			ans += sum;
			pq.pop();
			pq.push(-sum);
			
			first = 0;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
