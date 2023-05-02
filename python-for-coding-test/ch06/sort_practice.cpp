#include <iostream>
#include <vector>

using namespace std;

void selection_sort(vector<int> origin) {
	
	vector<int> v = origin;
	
	for(size_t i = 0; i < v.size() - 1; ++i) {
		int min_idx = i;
		
		for(size_t j = i + 1; j < v.size(); ++j)
			if(v[j] < v[min_idx])
				min_idx = j;
			
		int temp = v[i];
		v[i] = v[min_idx];
		v[min_idx] = temp;
	}
	
	for(int num : v)
		cout << num << ' ';
	cout << endl;
}

void insertion_sort(vector<int> origin) {
	
	vector<int> v = origin;
	
	for(size_t i = 1; i < v.size(); ++i) {
		int idx = i;
		for(size_t j = i - 1; j >= 0; --j) {
			if(v[idx] >= v[j])
				break;
			
			int temp = v[idx];
			v[idx] = v[j];
			v[j] = temp;
			idx = j;
		}
	}
	
	for(int num : v)
		cout << num << ' ';
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<int> vec = {3, 39, 48, 10, 49, 12};
	
	selection_sort(vec);
	insertion_sort(vec);
	
	return 0;
}
