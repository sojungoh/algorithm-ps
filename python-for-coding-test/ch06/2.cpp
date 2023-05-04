#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int partition(int p, int r) {
	int pivot = v[r];
	int i = p - 1;
	
	for(int j = p; j < r; ++j) {
		if(v[j] >= pivot) {
			++i;
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	
	v[r] = v[i + 1];
	v[i + 1] = pivot;
	
	return i + 1;
}

void quick_sort(int p, int r) {
	if(p <= r) {
		int q = partition(p, r);
		
		quick_sort(p, q - 1);
		quick_sort(q + 1, r);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, num;
	cin >> n;
	
	for(int i = 0; i < n; ++i) {
		cin >> num;
		v.push_back(num);
	}
	
	quick_sort(0, v.size() - 1);
	
	return 0;
}
