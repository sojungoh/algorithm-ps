#include <iostream>
#include <vector>

using namespace std;

void quick_sort(vector<int>& v, int s, int e) {
	if(s >= e)
		return;
	
	int p = v[s];
	int l = s + 1;
	int r = e;
	
	while(l <= r) {
		
		while(l <= e && v[l] <= p)
			l++;
		while(r > s && v[r] >= p)
			r--;
			
		if(l > r)
			break;
		
		int temp = v[l];
		v[l] = v[r];
		v[r] = temp;
	}
	
	v[s] = v[r];
	v[r] = p;
	
	quick_sort(v, s, r - 1);
	quick_sort(v, r + 1, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k, m;
	vector<int> a, b;
	
	cin >> n >> k;
	
	for(int i = 0; i < n; ++i) {
		cin >> m;
		a.push_back(m);
	}
	
	for(int i = 0; i < n; ++i) {
		cin >> m;
		b.push_back(m);
	}
	
	quick_sort(a, 0, a.size() - 1);
	quick_sort(b, 0, b.size() - 1);
	
	
	int ans = 0;
	size_t sz = b.size();
	
	for(int i = 1; i <= k; ++i) {
		if(a[i - 1] < b[sz - i])
			ans += b[sz - i];
		else
			ans += a[i - 1];
	}
	
	for(int i = k; i < a.size(); ++i)
		ans += a[i];
		
	cout << ans << endl;
	
	return 0;
}
